/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 10:41:39 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

static inline int	is_flag(char c)
{
	return (c == 'c' || c == 'd' || c == 'u'
		|| c == 'p' || c == 'x'
		|| c == 'X' || c == 'u'
		|| c == 's' || c == 'i'
		|| c == '%');
}

static int	numhelper(char c, va_list args)
{
	int	l;

	l = 0;
	if (c == 'u')
		ft_printunbr_fd(va_arg(args, unsigned int), 1, &l);
	else if (c == 'x')
		ft_printhex_fd(va_arg(args, unsigned int),
			"0123456789abcdef", &l, 1);
	else if (c == 'X')
		ft_printhex_fd(va_arg(args, unsigned int),
			"0123456789ABCDEF", &l, 1);
	else
		ft_printnbr_fd(va_arg(args, int), 1, &l);
	return (l);
}

static inline int	ptrhelper(va_list args)
{
	int				l;
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	l = 0;
	ft_printptr_fd(p, &l, 1);
	return (l);
}

static inline int	dispatch(char fmt, va_list args)
{
	if (fmt == 'c')
		return (ft_printchar_fd((char)va_arg(args, int), 1));
	else if (fmt == '%')
		return (ft_printchar_fd('%', 1));
	else if (fmt == 's')
		return (ft_printstr_fd(va_arg(args, char *), 1));
	else if (fmt == 'i' || fmt == 'd' || (fmt | 32) == 'x'
		|| fmt == 'u')
		return (numhelper(fmt, args));
	else if (fmt == 'p')
		return (ptrhelper(args));
	return (0);
}

__attribute__((__nonnull__(1)))
int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			c;

	c = 0;
	va_start(args, fmt);
	if (!*fmt)
		return (0);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			if (*fmt && is_flag(*fmt))
				c += dispatch(*fmt, args);
			++fmt;
			continue ;
		}
		(void)write (1, fmt, 1);
		++c;
		++fmt;
	}
	va_end(args);
	return (c);
}
