/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:36:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/17 01:30:55 by jaicastr         ###   ########.fr       */
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
	size_t			len;
	size_t			capacity;
	t_u8			*data;
}	t_str;

typedef struct s_vec
{
	t_u8						*head;
	size_t						capacity;
	const t_u8	*restrict		data;
}	t_vec;

#endif
