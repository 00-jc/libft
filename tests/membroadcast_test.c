/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   membroadcast_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_membroadcast_basic(void);
void	test_membroadcast_single(void);
void	test_membroadcast_edge(void);
void	test_membroadcast_large(void);

void	test_membroadcast_basic(void)
{
	char	dst[20];
	char	src[5];

	ft_bzero(dst, 20);
	memcpy(src, "ABCD", 5);
	ft_membroadcast(dst, src, 4, 4);
	assert(memcmp(dst, "ABCDABCDABCDABCD", 16) == 0);
}

void	test_membroadcast_single(void)
{
	char	dst[10];
	char	src;

	ft_bzero(dst, 10);
	src = 'X';
	ft_membroadcast(dst, &src, 1, 8);
	assert(memcmp(dst, "XXXXXXXX", 8) == 0);
}

void	test_membroadcast_edge(void)
{
	char	dst[20];
	char	src[3];

	ft_bzero(dst, 20);
	memcpy(src, "AB", 3);
	ft_membroadcast(dst, src, 2, 0);
	assert(dst[0] == 0);
	ft_membroadcast(dst, src, 0, 5);
	assert(dst[0] == 0);
}

void	test_membroadcast_large(void)
{
	char	dst[1024];
	char	src[9];
	int		i;

	ft_bzero(dst, 1024);
	memcpy(src, "PATTERN!", 9);
	ft_membroadcast(dst, src, 8, 100);
	i = 0;
	while (i < 100)
	{
		assert(memcmp(dst + (i * 8), "PATTERN!", 8) == 0);
		i++;
	}
}

int	main(void)
{
	printf("Testing ft_membroadcast...\n");
	test_membroadcast_basic();
	test_membroadcast_single();
	test_membroadcast_edge();
	test_membroadcast_large();
	printf("  ft_membroadcast: OK\n");
	return (0);
}
