/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_asm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 04:30:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/12 06:43:13 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_ASM_H
# define FT_P_ASM_H

# include "types.h"
# include <sys/types.h>

typedef struct t_512bits
{
	t_u8	_0;
	t_u8	_1;
	t_u8	_2;
	t_u8	_3;
	t_u8	_4;
	t_u8	_5;
	t_u8	_6;
	t_u8	_7;
	t_u8	_8;
	t_u8	_9;
	t_u8	_10;
	t_u8	_11;
	t_u8	_12;
	t_u8	_13;
	t_u8	_14;
	t_u8	_15;
	t_u8	_16;
	t_u8	_17;
	t_u8	_18;
	t_u8	_19;
	t_u8	_20;
	t_u8	_21;
	t_u8	_22;
	t_u8	_23;
	t_u8	_24;
	t_u8	_25;
	t_u8	_26;
	t_u8	_27;
	t_u8	_28;
	t_u8	_29;
	t_u8	_30;
	t_u8	_31;
	t_u8	_32;
	t_u8	_33;
	t_u8	_34;
	t_u8	_35;
	t_u8	_36;
	t_u8	_37;
	t_u8	_38;
	t_u8	_39;
	t_u8	_40;
	t_u8	_41;
	t_u8	_42;
	t_u8	_43;
	t_u8	_44;
	t_u8	_45;
	t_u8	_46;
	t_u8	_47;
	t_u8	_48;
	t_u8	_49;
	t_u8	_50;
	t_u8	_51;
	t_u8	_52;
	t_u8	_53;
	t_u8	_54;
	t_u8	_55;
	t_u8	_56;
	t_u8	_57;
	t_u8	_58;
	t_u8	_59;
	t_u8	_60;
	t_u8	_61;
	t_u8	_62;
	t_u8	_63;
} __attribute__((__may_alias__))	t_512bits;

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

typedef t_u32 * restrict const										t_blk32w;
typedef const t_u32 * restrict const								t_blk32r;
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

typedef __attribute__((vector_size(64), aligned(1), __may_alias__)) t_u64\
																	t_vu64_512;

typedef __attribute__((vector_size(64), aligned(64), __may_alias__)) t_u64\
																	t_vu64_512a;

typedef __attribute__((vector_size(64), aligned(1), __may_alias__)) t_u16\
																	t_vu16_512;

typedef __attribute__((vector_size(64), aligned(1), __may_alias__)) t_u32\
																	t_vu32_512;

typedef t_u32a * restrict const										t_blk32wa;
typedef const t_u32a * restrict const								t_blk32ra;
typedef t_u64a * restrict const										t_blk64wa;
typedef const t_u64a * restrict const								t_blk64ra;
typedef t_vu128a * restrict const									t_blk128wa;
typedef const t_vu128a * restrict const								t_blk128ra;
typedef t_vu256a * restrict const									t_blk256wa;
typedef const t_vu256a * restrict const								t_blk256ra;
typedef t_vu512a * restrict const									t_blk512wa;
typedef const t_vu512a * restrict const								t_blk512ra;

t_vu512			get_high512(void)\
					__attribute__((const));
t_vu512			get_lones512(void)\
					__attribute__((const));
t_vu512			get_z512(void)\
					__attribute__((const));
t_vu512			get_mask512(t_u8 x)\
					__attribute__((const));

t_vu256			get_high256(void)\
					__attribute__((const));
t_vu256			get_lones256(void)\
					__attribute__((const));
t_vu256			get_z256(void)\
					__attribute__((const));
t_vu256			get_mask256(t_u8 x)\
					__attribute__((const));

t_vu128			get_high128(void)\
					__attribute__((const));
t_vu128			get_lones128(void)\
					__attribute__((const));
t_vu128			get_z128(void)\
					__attribute__((const));
t_vu128			get_mask128(t_u8 x)\
					__attribute__((const));

t_u16a			ft_bitpack128(t_vu128a vec)\
					__attribute__((const));

#endif
