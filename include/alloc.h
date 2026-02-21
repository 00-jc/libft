/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 23:46:24 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>
# include <syscall.h>
# include <sys/mman.h>
# include "mem.h"

typedef struct s_slab
{
	size_t			total;
	size_t			used;
	t_u8			data[];
}	t_slab;

typedef struct s_hugepage
{
	struct s_hugepage	*next;
	struct s_hugepage	*prev;
	t_u8				data[];
}	t_hugepage;

typedef struct s_arena
{
	t_slab			*current;
	t_hugepage		*global;
}	t_arena;

typedef struct s_checkpoint
{
	size_t			total;
	size_t			used;
	t_hugepage		*location;
}	t_arena_checkpoint;

# define HUGEPAGE_SIZE 268435456ULL

# ifndef DEF_ALIGN
#  define DEF_ALIGN 32
# endif

void				*ft_alloc_align(size_t size, size_t align);
void				*ft_alloc(size_t size);
void				ft_free(void **ptr)\
						__attribute__((__nonnull__(1)));
void				ft_free_array(void ***arr)\
						__attribute__((__nonnull__(1)));
void				*ft_calloc(size_t n, size_t size);
void				*ft_extend(void *ptr, size_t n, size_t size);
void				*ft_extend_zero(void *ptr, size_t n, size_t size);
void				*ft_realloc(void *ptr, size_t n, size_t size);
void				*ft_recalloc(void *ptr, size_t n, size_t size);
void				*ft_mmap(size_t size, long prot_extra, long flags_extra);
void				ft_munmap(void *restrict const mem, size_t size)\
						__attribute__((nonnull(1)));
t_arena				ft_new_arena_alloc(void);
void				*ft_arena_alloc(t_arena *restrict const allocator,
						size_t size, size_t align)\
						__attribute__((nonnull(1)));
void				ft_destroy_arena(t_arena *alloc)\
						__attribute__((__nonnull__(1)));
t_arena_checkpoint	ft_arena_checkpoint(const t_arena *restrict const arena)\
						__attribute__((__nonnull__(1),\
						pure, __always_inline__));
void				ft_arena_rewind_clean(t_arena *restrict const arena,
						t_arena_checkpoint checkpoint);
void				ft_arena_rewind(t_arena *restrict const arena,
						t_arena_checkpoint checkpoint)\
						__attribute__((__always_inline__));

#endif
