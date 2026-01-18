/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:25:05 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 03:36:47 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"
#include <string.h>
#include <assert.h>

void	check_misaligned(char *h, char *w, char *l, char *uninit)
{
	assert(ft_strlen(h + 1) == strlen(h + 1));
	assert(ft_strlen(w + 2) == strlen(w + 2));
	assert(ft_strlen(l + 1) == strlen(l + 1));
	assert(ft_strlen(1 + uninit) == strlen(1 + uninit));
	assert(ft_strlen(l + 1) == strlen(l + 1));
	assert(ft_strlen(l + 10) == strlen(l + 10));
	assert(ft_strlen(l + 17) == strlen(l + 17));
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
	assert(ft_strlen(h) == strlen(h));
	assert(ft_strlen(w) == strlen(w));
	assert(ft_strlen(z) == strlen(z));
	assert(ft_strlen(l) == strlen(l));
	assert(ft_strlen(uninit) == strlen(uninit));
	return (0);
}
