/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopparg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:02:52 by jaicastr          #+#    #+#             */
/*   Updated: 2026/04/21 13:08:16 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOPPARG_H
# define CHOPPARG_H

# include "types.h"

typedef enum e_chopptype
{
	KEY_VALUE,
	PASSTHROUGH,
}	t_chopptype;

typedef struct s_choppkeyval
{
	t_buffer		name;
	t_buffer		value;
}	t_choppkeyval;

typedef union u_choppcontent
{
	t_choppkeyval	kv;
	t_buffer		passthrough;
}	t_choppcontent;

typedef struct s_choppresult
{
	t_chopptype		type;

}	t_choppresult;

typedef struct s_chopparg
{
	size_t		argc;
	t_u8		*argprev;
	t_u8		**args;
}	t_chopparg;

#endif
