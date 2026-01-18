/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:52:15 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/18 02:53:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

__attribute__((__always_inline__))
inline void	pputs(int fd, const char *restrict const str)
{
	if (!str)
		(void)write(fd, "(nil)", 5);
	else
		(void)write(fd, str, ft_strlen(str));
}
