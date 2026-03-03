/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hint.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:56:09 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/03 18:19:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HINT_H
# define HINT_H

void	ft_pin_invariant(int res);
void	ft_pin_invariant_msg(int res, char *msg)\
			__attribute__((__always_inline__, __nonnull__(2)));

#endif
