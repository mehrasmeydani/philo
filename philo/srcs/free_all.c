/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:27:53 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:43:16 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_all(t_philo *god)
{
	int	i;

	i = -1;
	if (god->philo_rout)
		free(god->philo_rout);
	if (god->forks.mutex)
	{
		while (++i < god->infos[0])
			pthread_mutex_destroy(&god->forks.mutex[i]);
		free(god->forks.mutex);
		if (god->alive_mutex)
			pthread_mutex_destroy(&god->forks.live);
		if (god->print_mutex)
			pthread_mutex_destroy(&god->forks.print);
		if (god->done_mutex)
			pthread_mutex_destroy(&god->forks.done);
	}
}

void	free_threads(t_philo *god, int i)
{
	ml(&god->forks.live);
	god->living = i;
	mu(&god->forks.live);
}
