/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:08:18 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/22 20:13:11 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_p_tok.h"

#ifdef __AVX512F__

t_token	ft_eat_while(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu512))
		return (ft_eat_while_u512(tk, set.eater512));
	else if (remaining >= sizeof(t_vu256))
		return (ft_eat_while_u256(tk, set.eater256));
	else if (remaining >= sizeof(t_vu128))
		return (ft_eat_while_u128(tk, set.eater128));
	else
		return (ft_eat_while_u8(tk, set.eater8));
}

#elif defined(__AVX2__)

t_token	ft_eat_while(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu256))
		return (ft_eat_while_u256(tk, set.eater256));
	else if (remaining >= sizeof(t_vu128))
		return (ft_eat_while_u128(tk, set.eater128));
	else
		return (ft_eat_while_u8(tk, set.eater8));
}

#else

t_token	ft_eat_while(t_tokenizer *tk, t_eater_select select)
{
	t_eaterset	set;
	size_t		remaining;

	set = get_eaterset(select);
	remaining = tk->max - tk->cc;
	if (remaining >= sizeof(t_vu128))
		return (ft_eat_while_u128(tk, set.eater128));
	else
		return (ft_eat_while_u8(tk, set.eater8));
}

#endif
