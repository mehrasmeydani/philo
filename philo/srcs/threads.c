/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:24:28 by megardes          #+#    #+#             */
/*   Updated: 2025/11/27 00:27:30 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	create_and_set_threads(t_philo *god)
{
	int	i;

	i = -1;
	while (++i < god->infos[0])
	{
		god->number_of_philos = i;
		if (god->infos[0] == 1)
			god->brains[i].f = &spaghetti_needs_two;
		else
			god->brains[i].f = god->route[god->philo_rout[i]];
		if (i == god->infos[0] - 1)
			god->brains[i].last_philo = 1;
		if (pthread_create(&god->brains[i].philo, NULL,
				start, &god->brains[i]))
			return (free_threads(god, i), i);
	}
	return (i);
}

int	create_thread(t_philo *god)
{
	int	i;
	int	j;

	if (pthread_create(&god->omnipotent, NULL, god_work, god))
		return (free_all(god), ft_put_endl("thread fail", 2), 0);
	i = create_and_set_threads(god);
	pthread_join(god->omnipotent, NULL);
	j = -1;
	while (++j < i)
		pthread_join(god->brains[j].philo, NULL);
	free(god->brains);
	god->brains = NULL;
	if (i != god->infos[0])
		ft_put_endl("thread_fail", 2);
	return (1);
}
