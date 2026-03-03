/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:52:15 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 18:50:22 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_io.h"

__attribute__((__always_inline__))
inline void	pputs(int fd, const char *restrict const str)
{
	ssize_t		unused;

	if (!str)
		unused = write(fd, "(nil)", 5);
	else
		unused = write(fd, str, ft_strlen(str));
	(void)(unused == 0);
}

__attribute__((__always_inline__))
inline void	putc_(char c, int fd)
{
	ssize_t		unused;

	unused = write(fd, &c, 1);
	(void)(unused == 0);
}
