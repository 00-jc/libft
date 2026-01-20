/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/20 02:34:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IO_H
# define IO_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "cstr.h"
# include "mem.h"
# include "alloc.h"

typedef struct s_file
{
	size_t				size;
	t_u8	*restrict	content;
}	t_file;

# ifndef BUFSIZE
#  define BUFSIZE 4096
# endif

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
void			ft_printf(const char *restrict const fmt, ...)\
					__attribute__((__nonnull__(1)));
void			ft_fprintf(int fd, const char *restrict const fmt, ...)\
					__attribute__((__nonnull__(2)));
t_file			ft_read_file(const char *restrict const fname)\
					__attribute__((__nonnull__(1)));
void			ft_close_file(t_file *restrict const f)\
					__attribute__((__nonnull__(1)));
#endif
