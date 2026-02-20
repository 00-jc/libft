/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:02:58 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 19:23:58 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMI_H
# define BMI_H

# include "types.h"

t_u64			__hasz64(t_u64 x);
t_u64			__populate(t_u8 y);

size_t			ft_memctz_u16(t_u16 x);
size_t			ft_memctz_u32(t_u32 x);
size_t			ft_memctz_u64(t_u64 x);
size_t			ft_memctz_u128(t_u128 x);

size_t			__max_s(size_t x, size_t y);
t_u8			__maxu8(t_u8 x, t_u8 y);
t_u32			__maxu32(t_u32 x, t_u32 y);
t_u64			__maxu64(t_u64 x, t_u64 y);
t_u128			__maxu128(t_u128 x, t_u128 y);

t_u16a			ft_bswap16(t_u16a x)\
					__attribute__((__always_inline__));
t_u32a			ft_bswap32(t_u32a x)\
					__attribute__((__always_inline__));
t_u64a			ft_bswap64(t_u64a x)\
					__attribute__((__always_inline__));

t_u16a			ft_to_be16(t_u16a x)\
					__attribute__((__always_inline__));
t_u32a			ft_to_be32(t_u32a x)\
					__attribute__((__always_inline__));
t_u64a			ft_to_be64(t_u64a x)\
					__attribute__((__always_inline__));

#endif
