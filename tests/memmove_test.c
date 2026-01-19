/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_memmove_basic(void);
void	test_memmove_overlap(void);
void	test_memmove_edge(void);
void	test_memmove_long(void);

void	test_memmove_basic(void)
{
	char	src[12];
	char	dst1[32];
	char	dst2[32];

	memcpy(src, "hello world", 12);
	ft_memmove(dst1, src, 12);
	memmove(dst2, src, 12);
	assert(memcmp(dst1, dst2, 12) == 0);
}

void	test_memmove_overlap(void)
{
	char	buf1[20];
	char	buf2[20];

	memcpy(buf1, "0123456789ABCDEF", 17);
	memcpy(buf2, "0123456789ABCDEF", 17);
	ft_memmove(buf1 + 4, buf1, 8);
	memmove(buf2 + 4, buf2, 8);
	assert(memcmp(buf1, buf2, 17) == 0);
	memcpy(buf1, "0123456789ABCDEF", 17);
	memcpy(buf2, "0123456789ABCDEF", 17);
	ft_memmove(buf1, buf1 + 4, 8);
	memmove(buf2, buf2 + 4, 8);
	assert(memcmp(buf1, buf2, 17) == 0);
}

void	test_memmove_edge(void)
{
	char	buf1[8];
	char	buf2[8];

	memcpy(buf1, "test", 5);
	memcpy(buf2, "test", 5);
	ft_memmove(buf1, buf1 + 1, 0);
	memmove(buf2, buf2 + 1, 0);
	assert(memcmp(buf1, buf2, 5) == 0);
	ft_memmove(buf1, buf1 + 3, 1);
	memmove(buf2, buf2 + 3, 1);
	assert(memcmp(buf1, buf2, 5) == 0);
}

void	test_memmove_long(void)
{
	char	buf1[512];
	char	buf2[512];
	int		i;

	i = 0;
	while (i < 512)
	{
		buf1[i] = (char)(i % 256);
		buf2[i] = (char)(i % 256);
		i++;
	}
	ft_memmove(buf1 + 100, buf1, 300);
	memmove(buf2 + 100, buf2, 300);
	assert(memcmp(buf1, buf2, 512) == 0);
}

int	main(void)
{
	printf("Testing ft_memmove...\n");
	test_memmove_basic();
	test_memmove_overlap();
	test_memmove_edge();
	test_memmove_long();
	printf("  ft_memmove: OK\n");
	return (0);
}
