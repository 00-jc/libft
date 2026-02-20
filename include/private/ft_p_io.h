/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:58:03 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 21:01:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_IO_H
# define FT_P_IO_H

# include "io.h"

void			putu(int fd, size_t n)\
					__attribute__((__always_inline__));
void			putx(int fd, size_t n, char or)\
					__attribute__((__always_inline__));
void			putd(int fd, ssize_t n)\
					__attribute__((__always_inline__));
void			puti(int fd, int n)\
					__attribute__((__always_inline__));
void			pputs(int fd, const char *restrict const str)\
					__attribute__((__always_inline__));
void			pflt(int fd, double d)\
					__attribute__((__always_inline__));
void			ft_putchar_fd(char c, int fd);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
