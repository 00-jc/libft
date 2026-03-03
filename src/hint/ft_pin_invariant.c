/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pin_invariant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:10:00 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 18:14:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_hint.h"

__attribute__((__always_inline__))
inline void	ft_pin_invariant(int res)
{
	if (!res)
		ft_hardcrash();
}

__attribute__((__always_inline__, __nonnull__(2)))
inline void	ft_pin_invariant_msg(int res, char *msg)
{
	if (!res)
		ft_hardcrash_with_message(msg);
}
