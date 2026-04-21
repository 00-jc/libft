/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/21 16:31:05 by jaicastr         ###   ########.fr       */
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
# include <syscall.h>

typedef struct s_file
{
	t_u8 *__restrict__		content;
	t_u32a					fd;
	size_t					size;
}	t_file;

typedef struct flock	t_flock;

# ifndef BUFSIZE
#  define BUFSIZE 4096
# endif

t_u32a			ft_fcntl(t_u32a fd, t_u32a cmd,
					const t_flock *__restrict__ const arg)\
					__attribute__((nonnull(3)));
void			ft_printf(const char *__restrict__ const fmt, ...)\
					__attribute__((__nonnull__(1)));
void			ft_fprintf(int fd, const char *__restrict__ const fmt, ...)\
					__attribute__((__nonnull__(2)));
void			ft_vfprintf(int fd, const char *fmt, va_list args)\
					__attribute__((__nonnull__(2), used));
t_file			ft_read_file(const char *__restrict__ const fname)\
					__attribute__((__nonnull__(1)));
void			ft_close_file(t_file *__restrict__ const f)\
					__attribute__((__nonnull__(1)));
t_u32a			ft_lockf(int fd);
t_u32a			ft_unlockf(int fd);

#endif
