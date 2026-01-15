/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 16:17:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>
# include "mem.h"
# include "macros.h"
# include "structs.h"

# ifndef DEF_ALIGN
#  define DEF_ALIGN 128
# endif

# ifndef DEFAULT_ARENA_SIZE
#  define DEFAULT_ARENA_SIZE 262272
# endif

void			*ft_alloc_align(size_t size, size_t align);
void			*ft_alloc(size_t size);
void			ft_free(void **ptr)\
					__attribute__((__nonnull__(1)));
void			ft_free_array(void ***arr)\
					__attribute__((__nonnull__(1)));
void			*ft_calloc(size_t n, size_t size);
void			*ft_extend(void *ptr, size_t n, size_t size);
void			*ft_extend_zero(void *ptr, size_t n, size_t size);
void			*ft_realloc(void *ptr, size_t n, size_t size);
void			*ft_recalloc(void *ptr, size_t n, size_t size);

#endif
