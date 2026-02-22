/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:57:48 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/22 20:30:07 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "mem.h"
# include "ctype.h"

typedef struct s_tokenizer
{
	t_u8	*mem;
	size_t	max;
	size_t	cc;
}	t_tokenizer;

typedef struct s_token
{
	t_u8	*mem;
	size_t	len;
}	t_token;

typedef enum e_eater_select
{
	set_blank,
	set_alpha,
	set_digit,
	set_xdigit,
}	t_eater_select;

t_token		ft_eat_while(t_tokenizer *tk, t_eater_select select);
t_token		ft_eat_until(t_tokenizer *tk, t_eater_select select);
t_u32a		ft_tokenizer_goto(t_tokenizer *tk, t_u8 byte)\
				__attribute__((__nonnull__(1)));
void		skip_whitespace(t_tokenizer *tk)\
				__attribute__((__nonnull__(1)));

#endif
