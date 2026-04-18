/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nanos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:02:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/18 20:18:56 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

#ifdef __x86_64__

__attribute__((__always_inline__))
inline t_u64a	ft_get_hz(void)
{
	t_u32a	eax;
	t_u32a	ebx;
	t_u32a	ecx;
	t_u32a	edx;

	__asm__ volatile (
		"cpuid"
		: "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
		: "a"(0x15), "c"(0)
	);
	return (((t_u64a)ecx * ebx) / eax);
}

__attribute__((__always_inline__))
inline t_u64a	ft_get_nanos(void)
{
	static t_u64a	hz = 0;
	t_u32a			hi;
	t_u32a			lo;
	t_u32a			aux;
	t_u64a			lane;

	if (__builtin_expect(hz == 0, 0))
		hz = ft_get_hz();
	__asm__ volatile ("rdtscp" : "=a"(lo), "=d"(hi), "=c"(aux));
	lane = (((t_u64a)hi << 32) | lo) * 1000000000;
	return (lane / hz);
}

#else

__attribute__((__always_inline__))
inline t_u64a	ft_get_nanos(void)
{
	struct timespec		ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (((t_u64a)ts.tv_sec * 1000000000) + (t_u64a)ts.tv_nsec);
}

#endif
