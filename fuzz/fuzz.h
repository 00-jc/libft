/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzz.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codex <codex@openai>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/04/23 00:00:00 by codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUZZ_H
# define FUZZ_H

# include "private/test.h"
# include "fuzzer.h"
# include <stdio.h>
# include <stdlib.h>

# define FUZZ_KEY_SLOTS 64
# define FUZZ_MEM_CAP 1024
# define FUZZ_STR_CAP 128
# define FUZZ_VEC_CAP 128

__attribute__((unused))
static size_t	fuzz_ptr_align(const void *ptr)
{
	size_t	align;

	align = 1;
	while ((((t_uptr)ptr & align) == 0) && align < (1UL << 20))
		align <<= 1;
	return (align);
}

#endif
