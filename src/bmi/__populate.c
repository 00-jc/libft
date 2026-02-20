/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __populate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 06:53:51 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/***** FUNCTION: __populate
 *
 *  Broadcasts a single byte to all 8 positions
 *  in a 64-bit word.
 *
 *  Does:
 *  	- Widens the byte to u64.
 *  	- Doubles the pattern at each shift stage:
 *  	  8 → 16 → 32 → 64 bits, filling all lanes.
 *
 *  	  e.g. 0x41 → 0x4141414141414141
 *
 *  WHY:
 *
 *  	Used by ft_memset to fill 8 bytes per store,
 *  	and by ft_memchr to XOR a search byte against
 *  	8 bytes at once (turning the target byte into
 *  	0x00, which __hasz then detects).
 *
 *  NOTES:
 *
 *  	The compiler will likely fold this into a
 *  	single imul on x86 at -O2+, but the explicit
 *  	shifts guarantee it works at -O0.
 *
 *  ERRORS:
 *
 *  	None.
 *
 *  SCOPE:
 *
 *  	+ Global
 *
 **************************************************/

__attribute__((hot, const, __always_inline__))
inline t_u64	__populate(t_u8 y)
{
	t_u64	x;

	x = (t_u64)y;
	x |= x << 8;
	x |= x << 16;
	x |= x << 24;
	x |= x << 32;
	return (x);
}
