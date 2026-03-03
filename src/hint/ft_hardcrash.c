/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcrash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:00:12 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 18:18:47 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_hint.h"
#include "private/ft_p_io.h"

#ifdef __x86_64__

__attribute__((__cold__, __always_inline__))
static inline void	ft__exit(int status)
{
	__asm__ volatile (
		"syscall"
		:
		: "a"(SYS_exit), "D"(status)
		: "rcx", "r11", "memory"
	);
}

#else

__attribute__((__cold__, __always_inline__))
static inline void	ft__exit(int status)
{
	syscall(SYS_exit, status);
}

#endif

__attribute__((__noreturn__, __cold__, __noinline__))
void	ft_hardcrash_with_message(char *msg)
{
	ft_fprintf(STDERR_FILENO, "%s\n", msg);
	ft__exit(1);
	while (1)
	{
		(void)0;
	}
}

__attribute__((__noreturn__, __cold__, __noinline__))
void	ft_hardcrash(void)
{
	ft__exit(1);
	while (1)
	{
		(void)0;
	}
}
