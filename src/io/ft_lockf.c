/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lockf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:58:49 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/17 16:22:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#ifdef __x86_64__

__attribute__((nonnull(3), __always_inline__))
t_u32a	ft_fcntl(t_u32a fd, t_u32a cmd,
		const t_flock *restrict const arg) {
	t_u32a	ret;

	__asm__ volatile (
		"syscall"
		: "=a" (ret)
		: "0" (SYS_fcntl),
		"D" (fd),
		"S" (cmd),
		"d" (arg)
		: "rcx", "r11", "memory"
	);
	return (ret);
}

#else

__attribute__((nonnull(3), __always_inline__))
t_u32a	ft_fcntl(t_u32a fd, t_u32a cmd, const t_flock *restrict const arg) {
	return (fcntl(fd, cmd, arg));
}

#endif

t_u32a	ft_lockf(int fd)
{
	struct flock	fl;

	fl = (struct flock)
	{
		.l_type = F_RDLCK,
		.l_whence = SEEK_SET,
		.l_start = 0,
		.l_len = 0,
	};
	return ((t_u32a)ft_fcntl((t_u32a)fd, F_SETLKW, &fl));
}

t_u32a	ft_unlockf(int fd)
{
	struct flock	fl;

	fl = (struct flock)
	{
		.l_type = F_UNLCK,
		.l_whence = SEEK_SET,
		.l_start = 0,
		.l_len = 0,
	};
	return (ft_fcntl((t_u32a)fd, F_SETLK, &fl));
}
