/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:27:53 by megardes          #+#    #+#             */
/*   Updated: 2025/11/26 17:24:32 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_all(t_philo *god)
{
	int	i;

	i = -1;
	if (god->philo_rout)
		free(god->philo_rout);
	if (god->brains)
	{
		free(god->brains);
		god->brains = NULL;
	}
	if (god->forks.mutex)
	{
		while (++i < god->infos[0])
			pthread_mutex_destroy(&god->forks.mutex[i]);
		free(god->forks.mutex);
		if (god->alive_mutex)
			pthread_mutex_destroy(&god->forks.live);
		if (god->done_mutex)
			pthread_mutex_destroy(&god->forks.done);
		if (god->here_mutex)
			pthread_mutex_destroy(&god->forks.here);
		if (god->start_mutex)
			pthread_mutex_destroy(&god->forks.start);
	}
}

void	free_threads(t_philo *god, int i)
{
	ml(&god->forks.live);
	god->living = i;
	mu(&god->forks.live);
}
