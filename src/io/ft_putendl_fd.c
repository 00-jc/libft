/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd (s, fd);
	(void)write (fd, "\n", 1);
}
