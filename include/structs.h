/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:36:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/15 03:40:49 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/types.h>
# include <stdint.h>

typedef unsigned char __attribute__((__may_alias__))					t_u8;

typedef uint32_t __attribute__((__may_alias__, __aligned__(1)))			t_u32;
typedef uint32_t __attribute__((__may_alias__, __aligned__(4)))			t_u32a;

typedef uint64_t __attribute__((__may_alias__, __aligned__(1)))			t_u64;
typedef uint64_t __attribute__((__may_alias__, __aligned__(8)))			t_u64a;

typedef __uint128_t __attribute__((__may_alias__, __aligned__(1)))		t_u128;
typedef __uint128_t __attribute__((__may_alias__, __aligned__(16)))		t_u128a;

typedef uintptr_t __attribute__((__may_alias__))						t_uptr;

typedef struct s_string
{
	size_t	len;
	size_t	alloc_size;
	char	*data;
}	t_string;

typedef struct s_vec
{
	size_t	size;
	void	*data;
	size_t	alloc_size;
	size_t	sizeof_type;
}	t_vec;

typedef struct s_arena
{
	size_t			size;
	size_t			offset;
	struct s_arena	*next;
	void			*pool;
}	t_arena;

#endif
