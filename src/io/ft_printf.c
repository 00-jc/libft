/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:58:49 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/20 04:39:55 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

__attribute__((__nonnull__(2), __always_inline__))
static inline size_t	manage_l(int fd, const char *const c,
		size_t remaining, va_list args)
{
	size_t	i;

	i = 1;
	if (remaining > 1)
	{
		if (c[1] == 'd')
			(putd(fd, va_arg(args, ssize_t)), i += 2);
		else if (c[1] == 'u')
			(putu(fd, va_arg(args, size_t)), i += 2);
		else if ((c[1] | 32) == 'x')
			(putx(fd, va_arg(args, size_t), (char)((c[1] == 'x') * 32)),
				i += 2);
	}
	else
		(putu(fd, va_arg(args, size_t)), i += 2);
	return (i);
}

__attribute__((__nonnull__(2), __always_inline__))
static inline size_t	manage(int fd, const char *const c,
		size_t remaining, va_list args)
{
	char	_c;
	size_t	i;

	i = 0;
	_c = *c;
	if (_c == 'x' || _c == 'X')
		(putx(fd, va_arg(args, size_t), (char)((_c == 'x') * 32)), i += 2);
	else if (_c == 'd')
		(puti(fd, va_arg(args, ssize_t)), i += 2);
	else if (_c == 'u')
		(putu(fd, va_arg(args, size_t)), i += 2);
	else if (_c == 'l' || _c == 'p')
		i += manage_l(fd, c, remaining, args);
	else if (_c == 's')
		(pputs(fd, va_arg(args, char *)), i += 2);
	else if (_c == 'f')
		(pflt(fd, va_arg(args, double)), i += 2);
	else if (_c == '%')
		((void)write(fd, "%", 1), i += 2);
	else if (_c == 'c')
		((void)ft_putchar_fd((char)va_arg(args, int), fd), i += 2);
	return (i);
}

__attribute__((__nonnull__(2)))
static void	ft_vfprintf(int fd, const char *restrict const fmt, va_list args)
{
	size_t					len;
	size_t					maxptr;
	const char	*restrict	subst;
	const char	*restrict	start;

	len = ft_strlen(fmt);
	maxptr = (t_uptr)fmt + len;
	start = fmt;
	subst = ft_memchr(fmt, '%', len);
	while (subst && start && (t_uptr)subst < maxptr)
	{
		(void)write(fd, start, (t_uptr)subst - (t_uptr)start);
		subst += manage(fd, subst + 1, maxptr - (t_uptr)(subst + 1), args);
		start = subst;
		len = maxptr - (t_uptr)start;
		subst = ft_memchr(start, '%', len);
	}
	(void)write(fd, start, maxptr - (t_uptr)start);
}

void	ft_fprintf(int fd, const char *restrict const fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	ft_vfprintf(fd, fmt, args);
	va_end(args);
}

void	ft_printf(const char *restrict const fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	ft_vfprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
}
