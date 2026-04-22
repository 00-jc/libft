/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzz.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codex <codex@openai>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:00:00 by codex             #+#    #+#             */
/*   Updated: 2026/04/23 01:22:08 by jaicastr         ###   ########.fr       */
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

#endif
