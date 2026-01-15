/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 04:55:07 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

__attribute__((nonnull(1, 2)))
inline static t_u8	ft_memswap_dyn(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	void	*buffer;

	if (!len)
		return (0);
	buffer = ft_alloc(len * sizeof(t_u8));
	if (!buffer)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	ft_free(&buffer);
	return (1);
}

__attribute__((nonnull(1, 2)))
inline static t_u8	ft_memswap_bounded(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	t_u8	buffer[BUFFER_SIZE];

	if (!len)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	return (1);
}

__attribute__((nonnull(1, 2)))
t_u8	ft_memswap(void *__restrict__ p1,
	void *__restrict__ p2, size_t len)
{
	if (len <= BUFFER_SIZE)
		return (ft_memswap_bounded(p1, p2, len));
	else
		return (ft_memswap_dyn(p1, p2, len));
}

__attribute__((nonnull(1, 2)))
inline t_u8	ft_memswap_extern(void *__restrict__ p1,
	void *__restrict__ p2, size_t len,
	void *__restrict__ buffer)
{
	if (!len)
		return (0);
	ft_memcpy(buffer, p1, len);
	ft_memcpy(p1, p2, len);
	ft_memcpy(p2, buffer, len);
	return (1);
}
