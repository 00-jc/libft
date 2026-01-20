/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_portable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 03:52:23 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/20 04:31:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "vec.h"

#ifndef __x86_64__

# ifndef FBUFFER_SIZE
#  define FBUFFER_SIZE 4096
# endif

__attribute__((__nonnull__(1)))
t_file	ft_read_file(const char *restrict const fname)
{
	int					ret;
	t_u8				stack[FBUFFER_SIZE];
	t_vec				buffer;

	buffer = ft_vec_new(FBUFFER_SIZE, sizeof(t_u8));
	if (buffer.data == NULL)
		return ((t_file){0});
	ret = open(fname, O_RDONLY);
	if (ret == -1)
		return ((t_file){0});
	while (read(ret, stack, FBUFFER_SIZE) > 0
		&& ft_vec_extend(&buffer, stack, sizeof(t_u8), FBUFFER_SIZE))
		;
	return ((t_file){.content = (t_u8 *)buffer.data,
		.size = (t_uptr)buffer.head - (t_uptr)buffer.content});
}

__attribute__((__nonnull__(1)))
inline void	ft_close_file(t_file *restrict const f)
{
	ft_free((void **)&f->content);
}

#endif
