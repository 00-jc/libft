/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_printhex_fd(unsigned int x, const char *set, int *l, int fd)
{
	char	o;

	if (x >= 16)
		ft_printhex_fd(x >> 4, set, l, fd);
	o = set[x & 0xF];
	*l += write(fd, &o, 1);
}
