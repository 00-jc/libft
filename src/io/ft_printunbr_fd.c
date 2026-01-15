/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_printunbr_fd(unsigned int n, int fd, int *len)
{
	char	o;

	if (n >= 10)
	{
		ft_printnbr_fd(n / 10, fd, len);
		ft_printnbr_fd(n % 10, fd, len);
	}
	else
	{
		o = (n % 10) + '0';
		*len = *len + 1;
		(void)write(fd, &o, 1);
	}
}
