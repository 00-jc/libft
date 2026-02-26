/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_portable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 03:52:23 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 05:52:46 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "vec.h"

#ifndef __x86_64__

__attribute__((__nonnull__(1)))
t_file	ft_read_file(const char *restrict const fname)
{
	ssize_t				ret;
	int					fd;
	t_vec				buffer;

	buffer = ft_vec_new(BUFSIZE, sizeof(t_u8));
	if (buffer.data == NULL)
		return ((t_file){0});
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (ft_vec_free(&buffer), (t_file){0});
	ret = read(fd, (void *)buffer.data, BUFSIZE);
	while (ret > 0)
	{
		buffer.head += ret;
		if (!ft_vec_reserve(&buffer, sizeof(t_u8), BUFSIZE))
			return ((void)close(fd), (t_file){0});
		ret = read(fd, (void *)buffer.head, BUFSIZE);
	}
	return ((t_file){.content = (t_u8 *)buffer.data,
		.size = (t_uptr)buffer.head - (t_uptr)buffer.data,
		.fd = (t_u32)fd});
}

__attribute__((__nonnull__(1)))
inline void	ft_close_file(t_file *restrict const f)
{
	(void)close((int)f->fd);
	ft_free((void **)&f->content);
}

#endif
