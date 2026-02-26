/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:52:15 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/23 17:24:29 by jaicastr         ###   ########.fr       */
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
	(void)unused;
}
