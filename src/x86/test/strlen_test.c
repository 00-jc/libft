/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:25:05 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 10:53:01 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"
#include <string.h>
#include <assert.h>

#define LONG "10000===00000000000000000000000000000000000000000000"\
		"00000000000000000000000000000000900???????????????????????????"\
		"?????????00000000000000000000000000000000000000000000000000000"\
		"00000000ññññññññññññññññçççççççççççç"

void	check_misaligned(char *h, char *w, char *l, char *uninit);

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
	char __attribute__	((aligned(64)))	h[6];
	char __attribute__	((aligned(64)))	w[6];
	char __attribute__	((aligned(64)))	z[1];
	char __attribute__	((aligned(64)))	l[sizeof(LONG)];

	memcpy(h, "hello", 6);
	memcpy(w, "world", 6);
	memcpy(z, "\0\0", 1);
	memcpy(l, LONG, sizeof(LONG));
	assert(ft_strlen(h) == strlen(h));
	assert(ft_strlen(w) == strlen(w));
	assert(ft_strlen(z) == strlen(z));
	assert(ft_strlen(l) == strlen(l));
	return (0);
}
