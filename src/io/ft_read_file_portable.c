/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_portable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 03:52:23 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/10 21:56:28 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "vec.h"

#ifndef __x86_64__

__attribute__((__nonnull__(1)))
t_file	ft_read_file(const char *restrict const fname)
{
	int					ret;
	int					fd;
	t_u8				stack[BUFSIZE];
	t_vec				buffer;

	buffer = ft_vec_new(BUFSIZE, sizeof(t_u8));
	if (buffer.data == NULL)
		return ((t_file){0});
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (ft_vec_free(&buffer), (t_file){0});
	ret = read(fd, stack, BUFSIZE);
	while (ret > 0 && ft_vec_extend(&buffer,
			stack, sizeof(t_u8), (size_t)ret))
		ret = read(fd, stack, BUFSIZE);
	(void)close(fd);
	return ((t_file){.content = (t_u8 *)buffer.data,
		.size = (t_uptr)buffer.head - (t_uptr)buffer.content});
}

__attribute__((__nonnull__(1)))
inline void	ft_close_file(t_file *restrict const f)
{
	ft_free((void **)&f->content);
}

#endif
