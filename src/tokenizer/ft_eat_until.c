/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:08:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/22 20:18:17 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_tok.h"

#ifdef __AVX512F__

t_token	ft_eat_until(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu512a))
		return (ft_eat_until_u512(tk, set.eater512));
	else if (remaining >= sizeof(t_vu256a))
		return (ft_eat_until_u256(tk, set.eater256));
	else if (remaining >= sizeof(t_vu128a))
		return (ft_eat_until_u128(tk, set.eater128));
	else
		return (ft_eat_until_u8(tk, set.eater8));
}

#elif defined(__AVX2__)

t_token	ft_eat_until(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu256a))
		return (ft_eat_until_u256(tk, set.eater256));
	else if (remaining >= sizeof(t_vu128a))
		return (ft_eat_until_u128(tk, set.eater128));
	else
		return (ft_eat_until_u8(tk, set.eater8));
}

#else

t_token	ft_eat_until(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu128a))
		return (ft_eat_until_u128(tk, set.eater128));
	else
		return (ft_eat_until_u8(tk, set.eater8));
}

#endif
