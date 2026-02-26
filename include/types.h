/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 03:36:25 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 20:58:56 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/types.h>
# include <stdint.h>

typedef uint8_t __attribute__((__may_alias__))							t_u8;

typedef uint16_t __attribute__((__may_alias__, __aligned__(1)))			t_u16;
typedef uint16_t __attribute__((__may_alias__, __aligned__(2)))			t_u16a;

typedef uint32_t __attribute__((__may_alias__, __aligned__(1)))			t_u32;
typedef uint32_t __attribute__((__may_alias__, __aligned__(4)))			t_u32a;

typedef uint64_t __attribute__((__may_alias__, __aligned__(1)))			t_u64;
typedef uint64_t __attribute__((__may_alias__, __aligned__(8)))			t_u64a;

typedef __uint128_t __attribute__((__may_alias__, __aligned__(1)))		t_u128;
typedef __uint128_t __attribute__((__may_alias__, __aligned__(16)))		t_u128a;

typedef uintptr_t __attribute__((__may_alias__))						t_uptr;

#endif
