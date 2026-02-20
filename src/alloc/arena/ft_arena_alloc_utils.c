/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_alloc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:14:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 18:12:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_arena.h"

__attribute__((nonnull(1), returns_nonnull, __always_inline__))
inline void	*get_next_ptr(t_slab *slab, size_t align)
{
	void	*addr;
	t_u8	*base;
	size_t	align_overhead;

	base = slab->data + slab->used;
	align_overhead = align - 1;
	addr = (void *)(((t_uptr)base + (align_overhead)) & ~(align_overhead));
	return (addr);
}

t_hugepage	*new_hugepage(t_hugepage *restrict const prev)
{
	t_hugepage	*page;
	t_slab		*slab;

	if (prev && prev->next)
	{
		page = prev->next;
		slab = (t_slab *)(page->data);
		slab->total = HUGEPAGE_SIZE - (sizeof(t_hugepage) + sizeof(t_slab));
		slab->used = 0;
		return (page);
	}
	page = ft_mmap(HUGEPAGE_SIZE, 0, MAP_HUGE_256MB);
	if (page == MAP_FAILED)
		return (NULL);
	if (prev)
		prev->next = page;
	page->next = 0;
	page->prev = prev;
	slab = (t_slab *)(page->data);
	slab->total = HUGEPAGE_SIZE - (sizeof(t_hugepage) + sizeof(t_slab));
	slab->used = 0;
	return (page);
}

__attribute__((nonnull(1)))
t_u32a	ft_arena_move_fwd(t_arena *alloc)
{
	t_hugepage	*old;

	old = alloc->global;
	alloc->global = new_hugepage(old);
	if (!alloc->global)
	{
		alloc->global = old;
		return (0);
	}
	alloc->current = (t_slab *)alloc->global->data;
	return (1);
}
