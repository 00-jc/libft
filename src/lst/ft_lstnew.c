/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by jaicastr          #+#    #+#             */
/*   Updated: 2026/01/14 02:10:15 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newl;

	newl = (t_list *)ft_alloc(sizeof(t_list));
	if (!newl)
		return (NULL);
	newl->content = content;
	newl->next = NULL;
	return (newl);
}
