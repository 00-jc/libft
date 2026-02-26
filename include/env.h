/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 01:02:39 by jaicastr          #+#    #+#             */
/*   Updated: 2026/02/19 01:18:07 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "mem.h"

extern char		**environ;

char			*ft_getenv(const char *restrict const var)\
					__attribute__((__nonnull__(1)));

#endif
