/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:39:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 09:26:02 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "lft.h"
#include <string.h>
#include <assert.h>

void	check_misaligned(char *h, char *w, char *l)
{
	assert(ft_memchr(h + 1, 'e', 4) == memchr(h + 1, 'e', 4));
	assert(ft_memchr(h + 1, 'l', 4) == memchr(h + 1, 'l', 4));
	assert(ft_memchr(h + 3, 'l', 2) == memchr(h + 3, 'l', 2));
	assert(ft_memchr(h + 4, 'o', 1) == memchr(h + 4, 'o', 1));
	assert(ft_memchr(w + 2, 'r', 3) == memchr(w + 2, 'r', 3));
	assert(ft_memchr(w + 3, 'l', 2) == memchr(w + 3, 'l', 2));
	assert(ft_memchr(w + 1, 'o', 4) == memchr(w + 1, 'o', 4));
	assert(ft_memchr(l + 1, '=', 50) == memchr(l + 1, '=', 50));
	assert(ft_memchr(l + 10, '?', 100) == memchr(l + 10, '?', 100));
	assert(ft_memchr(l + 15, '0', 200) == memchr(l + 15, '0', 200));
	assert(ft_memchr(l + 31, '?', 100) == memchr(l + 31, '?', 100));
	assert(ft_memchr(l + 63, '?', 50) == memchr(l + 63, '?', 50));
	assert(ft_memchr(l + 100, '=', 50) == memchr(l + 100, '=', 50));
	assert(ft_memchr(h + 5, 'h', 1) == memchr(h + 5, 'h', 1));
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

void	test_edge_cases(char *h, char *w, char *l)
{
	assert(ft_memchr(h, 'h', 0) == memchr(h, 'h', 0));
	assert(ft_memchr(h, 'e', 1) == memchr(h, 'e', 1));
	assert(ft_memchr(h, 'h', 1) == memchr(h, 'h', 1));
	assert(ft_memchr(h, 'e', 1) == memchr(h, 'e', 1));
	assert(ft_memchr(w, 'w', 1) == memchr(w, 'w', 1));
	assert(ft_memchr(l, '1', 1) == memchr(l, '1', 1));
	assert(ft_memchr(h, 'e', 2) == memchr(h, 'e', 2));
	assert(ft_memchr(h, 'e', 1) == memchr(h, 'e', 1));
	assert(ft_memchr(h, 'l', 5) == memchr(h, 'l', 5));
	assert(ft_memchr(h + 3, 'l', 2) == memchr(h + 3, 'l', 2));
	assert(ft_memchr(h, '\0', 6) == memchr(h, '\0', 6));
	assert(ft_memchr(h, '\0', 5) == memchr(h, '\0', 5));
	assert(ft_memchr(h, '\0', 4) == memchr(h, '\0', 4));
	assert(ft_memchr(h, 'x', 4) == memchr(h, 'x', 4));
	assert(ft_memchr(l + 85, '\r', 1) == memchr(l + 85, '\r', 1));
	assert(ft_memchr(h, 'h', 1000) == memchr(h, 'h', 1000));
	assert(ft_memchr(w, 'd', 1000) == memchr(w, 'd', 1000));
}

void	test_long_string(char *l)
{
	assert(ft_memchr(l, '=', 240) == memchr(l, '=', 240));
	assert(ft_memchr(l, '?', 240) == memchr(l, '?', 240));
	assert(ft_memchr(l, '\r', 240) == memchr(l, '\r', 240));
	assert(ft_memchr(l, 'x', 240) == memchr(l, 'x', 240));
	assert(ft_memchr(l, '0', 240) == memchr(l, '0', 240));
}

int	main(void)
{
	char __attribute__	((aligned(64)))	*h;
	char __attribute__	((aligned(64)))	*w;
	char __attribute__	((aligned(64)))	*z;
	char __attribute__	((aligned(64)))	*l;

	h = "hello";
	w = "world";
	z = "";
	l = "1000===0000000000000000000000000000000000000\
		 000000000000000000000000000000000000000\r00\
		 ????????????????????????????????????000000\
		 000000000000000000000000000000000000000000\
		 00000000000000ññññññññññññññññçççççççççççç";
	test_basic(h, w, z);
	test_long_string(l);
	check_misaligned(h, w, l);
	test_edge_cases(h, w, l);
	return (0);
}
