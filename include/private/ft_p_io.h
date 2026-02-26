/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:58:03 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/23 17:53:25 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_IO_H
# define FT_P_IO_H

# include "io.h"

void			putu(int fd, size_t n);
void			putx(int fd, size_t n, char or);
void			putd(int fd, ssize_t n);
void			puti(int fd, int n);
void			pputs(int fd, const char *restrict const str);
void			pflt(int fd, double d);
void			ft_putchar_fd(char c, int fd);

#endif
