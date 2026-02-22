/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_asm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 04:30:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/21 16:47:46 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_ASM_H
# define FT_P_ASM_H

# include "types.h"
# include <sys/types.h>

typedef t_u8 * restrict const										t_blk8w;
typedef const t_u8 * restrict const									t_blk8r;

/*
 *  Misaligned
 */

typedef __attribute__((vector_size(16), aligned(1), __may_alias__)) t_u8\
																	t_vu128;

typedef __attribute__((vector_size(32), aligned(1), __may_alias__)) t_u8\
																	t_vu256;

typedef __attribute__((vector_size(64), aligned(1), __may_alias__)) t_u8\
																	t_vu512;

typedef t_u64 * restrict const										t_blk64w;
typedef const t_u64 * restrict const								t_blk64r;
typedef t_vu128 * restrict const									t_blk128w;
typedef const t_vu128 * restrict const								t_blk128r;
typedef t_vu256 * restrict const									t_blk256w;
typedef const t_vu256 * restrict const								t_blk256r;
typedef t_vu512 * restrict const									t_blk512w;
typedef const t_vu512 * restrict const								t_blk512r;

/*
 *  Aligned
 */

typedef __attribute__((vector_size(16), aligned(16), __may_alias__)) t_u8\
																	t_vu128a;

typedef __attribute__((vector_size(32), aligned(32), __may_alias__)) t_u8\
																	t_vu256a;

typedef __attribute__((vector_size(64), aligned(64), __may_alias__)) t_u8\
																	t_vu512a;

typedef t_u64a * restrict const										t_blk64wa;
typedef const t_u64a * restrict const								t_blk64ra;
typedef t_vu128a * restrict const									t_blk128wa;
typedef const t_vu128a * restrict const								t_blk128ra;
typedef t_vu256a * restrict const									t_blk256wa;
typedef const t_vu256a * restrict const								t_blk256ra;
typedef t_vu512a * restrict const									t_blk512wa;
typedef const t_vu512a * restrict const								t_blk512ra;

t_vu512			get_high512(void)\
					__attribute__((const, __always_inline__));
t_vu512			get_lones512(void)\
					__attribute__((const, __always_inline__));
t_vu512			get_z512(void)\
					__attribute__((const, __always_inline__));
t_vu512			get_mask512(t_u8 x)\
					__attribute__((const, __always_inline__));

t_vu256			get_high256(void)\
					__attribute__((const, __always_inline__));
t_vu256			get_lones256(void)\
					__attribute__((const, __always_inline__));
t_vu256			get_z256(void)\
					__attribute__((const, __always_inline__));
t_vu256			get_mask256(t_u8 x)\
					__attribute__((const, __always_inline__));

t_vu128			get_high128(void)\
					__attribute__((const, __always_inline__));
t_vu128			get_lones128(void)\
					__attribute__((const, __always_inline__));
t_vu128			get_z128(void)\
					__attribute__((const, __always_inline__));
t_vu128			get_mask128(t_u8 x)\
					__attribute__((const, __always_inline__));

t_u16a			ft_bitpack128(t_vu128a vec)\
					__attribute__((const, __always_inline__));

#endif
