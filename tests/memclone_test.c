/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memclone_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:00:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/19 04:38:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_memclone_basic(void);
void	test_memclone_binary(void);
void	test_memclone_edge(void);
void	test_memclone_large(void);

void	test_memclone_basic(void)
{
	char	src[12];
	void	*clone;

	memcpy(src, "hello world", 12);
	clone = ft_memclone(src, 12);
	assert(clone != NULL);
	assert(clone != src);
	assert(memcmp(clone, src, 12) == 0);
	ft_free(&clone);
}

void	test_memclone_binary(void)
{
	unsigned char	src[6];
	void			*clone;

	src[0] = 0x00;
	src[1] = 0xFF;
	src[2] = 0x80;
	src[3] = 0x01;
	src[4] = 0x7F;
	src[5] = 0xAB;
	clone = ft_memclone(src, 6);
	assert(clone != NULL);
	assert(memcmp(clone, src, 6) == 0);
	ft_free(&clone);
}

void	test_memclone_edge(void)
{
	char	src[5];
	void	*clone;

	memcpy(src, "test", 5);
	clone = ft_memclone(src, 0);
	assert(clone == NULL);
}

void	test_memclone_large(void)
{
	char	src[1024];
	void	*clone;
	int		i;

	i = 0;
	while (i < 1024)
	{
		src[i] = (char)(i % 256);
		i++;
	}
	clone = ft_memclone(src, 1024);
	assert(clone != NULL);
	assert(memcmp(clone, src, 1024) == 0);
	ft_free(&clone);
}

int	main(void)
{
	printf("Testing ft_memclone...\n");
	test_memclone_basic();
	test_memclone_binary();
	test_memclone_edge();
	test_memclone_large();
	printf("  ft_memclone: OK\n");
	return (0);
}
