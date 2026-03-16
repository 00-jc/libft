/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threadpool_wait.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:15:42 by jaicastr          #+#    #+#             */
/*   Updated: 2026/03/16 16:40:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"

__attribute__((__nonnull__(1)))
void	ft_threadpool_wait(t_threadpool *tp)
{
	pthread_mutex_lock(&tp->mutex);
	while (tp->count > 0)
		pthread_cond_wait(&tp->done, &tp->mutex);
	pthread_mutex_unlock(&tp->mutex);
}
