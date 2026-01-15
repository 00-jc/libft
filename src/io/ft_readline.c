/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 02:10:01 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

t_string	ft_readline(t_string *prompt, bool clean)
{
	t_string	out;
	char		c;

	if (clean)
		return ((void)ft_fgetc(0, true), (t_string){0});
	out = ft_tstr_new(100);
	(void)write(1, prompt->data, prompt->len);
	c = ft_fgetc(0, false);
	while (c != EOF && c != '\n')
	{
		ft_tstr_push(&out, c);
		c = ft_fgetc(0, false);
	}
	if (!out.len && out.alloc_size && c == EOF)
		return (ft_tstr_free(&out), (t_string){0});
	return (out);
}
