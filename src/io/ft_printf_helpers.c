/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:54:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 02:53:31 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

__attribute__((__always_inline__))
inline void	putu(int fd, size_t n)
{
	char			buffer[32];
	size_t			i;

	i = 32;
	if (n == 0)
		buffer[--i] = '0';
	while (n)
	{
		buffer[--i] = (char)((n % 10) + '0');
		n = n * 0xCCCCCCCDULL >> 35;
	}
	(void)write(fd, buffer + i, 32 - i);
}

__attribute__((__always_inline__))
inline void	putx(int fd, size_t n, char or)
{
	char			buffer[32];
	size_t			i;
	char			h;

	i = 32;
	if (n == 0)
		buffer[--i] = '0';
	while (n)
	{
		h = (char)(n & 0x0F);
		buffer[--i] = (char)((h + '0' + + ((h + 6) >> 4) * 7) | or);
		n >>= 4;
	}
	(void)write(fd, buffer + i, 32 - i);
}

__attribute__((__always_inline__))
inline void	putd(int fd, ssize_t n)
{
	char			buffer[32];
	t_u8			neg;
	size_t			i;

	i = 32;
	if (n == 0)
		buffer[--i] = '0';
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n)
	{
		buffer[--i] = (char)((n % 10) + '0');
		n /= 10;
	}
	if (neg)
		buffer[--i] = '-';
	(void)write(fd, buffer + i, 32 - i);
}

__attribute__((__always_inline__))
inline void	puti(int fd, int n)
{
	static char		buffer[32];
	t_u8			neg;
	size_t			i;

	i = 32;
	if (n == 0)
		buffer[--i] = '0';
	if (n == INT_MIN)
	{
		buffer[--i] = '8';
		n = -(n / 10);
	}
	neg = 0;
	if (n < 0)
		neg = 1;
	n = (neg == 1) * -n | (neg != 1) * n;
	while (n)
	{
		buffer[--i] = (char)((n % 10) + '0');
		n /= 10;
	}
	if (neg)
		buffer[--i] = '-';
	(void)write(fd, buffer + i, 32 - i);
}

__attribute__((__always_inline__))
inline void	pflt(int fd, double d)
{
	char		buffer[32];
	size_t		i;
	double		frac;

	putd(fd, (ssize_t)d);
	(void)write(fd, ".", 1);
	frac = (double)(d - (double)(size_t)d);
	i = 0;
	while (i < 6)
	{
		frac *= 10.0;
		buffer[i++] = (char)((size_t)frac % 10) + '0';
	}
	(void)write(fd, buffer, 6);
}
