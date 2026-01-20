/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 02:23:38 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/20 04:07:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#ifdef __x86_64__

__attribute__((__always_inline__))
static inline void	*ft_fmap(size_t size, int fd)
{
	void	*ret;

	__asm__ volatile (
		"mov $0x09, %%rax\n\t"
		"mov %1, %%rdi\n\t"
		"mov %2, %%rsi\n\t"
		"mov %3, %%rdx\n\t"
		"mov %4, %%r10\n\t"
		"mov %5, %%r8\n\t"
		"mov $0, %%r9\n\t"
		"syscall\n\t"
		"mov %%rax, %0"
		: "=r"(ret)
		: "r"((long) NULL),
		"r"((long)size),
		"r"((long)PROT_READ),
		"r"((long)MAP_PRIVATE),
		"r"((long)fd)
		: "%rax", "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9", "memory"
	);
	return (ret);
}

__attribute__((__nonnull__(1), __always_inline__))
static inline int	ft_stat(const char *restrict path, struct stat *statbuf)
{
	int	ret;

	__asm__ volatile (
		"mov $0x04, %%rax\n\t"
		"mov %1, %%rdi\n\t"
		"mov %2, %%rsi\n\t"
		"syscall\n\t"
		"mov %%eax, %0"
		: "=r"(ret)
		: "r"(path),
		"r"(statbuf)
		: "%rax", "%rdi", "%rsi", "memory"
	);
	return (ret);
}

__attribute__((__nonnull__(1)))
t_file	ft_read_file(const char *restrict const fname)
{
	int					ret;
	struct stat			st;
	void				*ptr;

	ret = ft_stat(fname, &st);
	if (ret == -1)
		return ((t_file){0});
	ret = open(fname, O_RDONLY);
	if (ret == -1)
		return ((t_file){0});
	ptr = ft_fmap((size_t)st.st_size, ret);
	return ((t_file){.content = ptr, .size = (size_t)st.st_size});
}

__attribute__((__nonnull__(1)))
inline void	ft_close_file(t_file *restrict const f)
{
	int	ret;

	__asm__ volatile (
		"mov $0x0b, %%rax\n\t"
		"mov %1, %%rdi\n\t"
		"mov %2, %%rsi\n\t"
		"syscall\n\t"
		"mov %%eax, %0"
		: "=r"(ret)
		: "r"(f->content),
		"r"(f->size)
		: "%rax", "%rdi", "%rsi", "memory"
	);
}

#endif
