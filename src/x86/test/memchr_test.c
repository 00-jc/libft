/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:39:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 03:41:13 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "lft.h"
#include <string.h>
#include <assert.h>

void	check_misaligned(char *h, char *w, char *l, char *uninit)
{
	assert(ft_memchr(h + 1, 'e', 4) == memchr(h + 1, 'e', 4));
	assert(ft_memchr(w + 2, 'r', 3) == memchr(w + 2, 'r', 3));
	assert(ft_memchr(l + 1, '=', 50) == memchr(l + 1, '=', 50));
	assert(ft_memchr(1 + uninit, '\0', 20) == memchr(1 + uninit, '\0', 20));
	assert(ft_memchr(l + 10, '?', 100) == memchr(l + 10, '?', 100));
}

void	test_basic(char *h, char *w, char *z)
{
	assert(ft_memchr(h, 'h', 5) == memchr(h, 'h', 5));
	assert(ft_memchr(h, 'e', 5) == memchr(h, 'e', 5));
	assert(ft_memchr(h, 'o', 5) == memchr(h, 'o', 5));
	assert(ft_memchr(w, 'w', 5) == memchr(w, 'w', 5));
	assert(ft_memchr(h, 'x', 5) == memchr(h, 'x', 5));
	assert(ft_memchr(z, 'a', 0) == memchr(z, 'a', 0));
	assert(ft_memchr(h, '\0', 6) == memchr(h, '\0', 6));
}

void	test_long_string(char *l)
{
	assert(ft_memchr(l, '=', 300) == memchr(l, '=', 300));
	assert(ft_memchr(l, '?', 300) == memchr(l, '?', 300));
	assert(ft_memchr(l, '\r', 300) == memchr(l, '\r', 300));
	assert(ft_memchr(l, 'x', 300) == memchr(l, 'x', 300));
	assert(ft_memchr(l, '0', 300) == memchr(l, '0', 300));
}

void	test_binary(void)
{
	unsigned char	b[256];
	int				i;

	i = -1;
	while (++i < 256)
		b[i] = (unsigned char)i;
	i = -1;
	while (++i < 256)
		assert(ft_memchr(b, i, 256) == memchr(b, i, 256));
}

int	main(void)
{
	char __attribute__	((aligned(64)))	*h;
	char __attribute__	((aligned(64)))	*w;
	char __attribute__	((aligned(64)))	*z;
	char __attribute__	((aligned(64)))	*l;
	char __attribute__	((aligned(64)))	*uninit;

	h = "hello";
	w = "world";
	z = "";
	l = "1000===0000000000000000000000000000000000000\
		 000000000000000000000000000000000000000\r00\
		 ????????????????????????????????????000000\
		 000000000000000000000000000000000000000000\
		 00000000000000ññññññññññññññññçççççççççççç";
	uninit = (char *)(t_uptr)main;
	test_basic(h, w, z);
	test_long_string(l);
	test_binary();
	check_misaligned(h, w, l, uninit);
	assert(ft_memchr(uninit, '\0', 50) == memchr(uninit, '\0', 50));
	return (0);
}
