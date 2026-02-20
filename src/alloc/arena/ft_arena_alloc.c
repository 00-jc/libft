/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/20 04:34:33 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_arena.h"

t_arena	ft_new_arena_alloc(void)
{
	t_hugepage		*initial_page;

	initial_page = new_hugepage(NULL);
	if (!initial_page)
		return ((t_arena){0});
	return ((t_arena)
		{
			.global = initial_page,
			.current = (t_slab *)initial_page->data
		});
}

__attribute__((__nonnull__(1), __always_inline__))
inline void	ft_arena_clean_fwd(const t_arena *restrict const alloc)
{
	t_hugepage	*x;
	t_hugepage	*next;

	next = alloc->global->next;
	while (next)
	{
		x = next->next;
		ft_munmap(next, HUGEPAGE_SIZE);
		next = x;
	}
	alloc->global->next = NULL;
}

__attribute__((__nonnull__(1)))
void	ft_destroy_arena(t_arena *alloc)
{
	t_hugepage	*x;
	t_hugepage	*next;

	ft_arena_clean_fwd(alloc);
	x = alloc->global;
	while (x)
	{
		next = x->prev;
		ft_munmap(x, HUGEPAGE_SIZE);
		x = next;
	}
}

__attribute__((nonnull(1)))
void	*ft_arena_alloc(t_arena *restrict const allocator,
	size_t size, size_t align)
{
	void	*next_ptr;
	size_t	waste;

	if ((size >= (HUGEPAGE_SIZE - (sizeof(t_slab) + sizeof(t_hugepage))))
		|| align == 0 || (align & (align - 1)) != 0)
		return (NULL);
	next_ptr = get_next_ptr(allocator->current, align);
	waste = (size_t)((t_u8 *)next_ptr - (allocator->current->data
				+ allocator->current->used));
	if ((t_u8 *)next_ptr + size > allocator->current->data
		+ allocator->current->total)
	{
		if (!ft_arena_move_fwd(allocator))
			return (NULL);
		next_ptr = get_next_ptr(allocator->current, align);
		waste = (size_t)((t_u8 *)next_ptr - (allocator->current->data
					+ allocator->current->used));
	}
	allocator->current->used += waste + size;
	return (next_ptr);
}
