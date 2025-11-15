/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:24:44 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:52:09 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	set_brains(t_philo *god, int i)
{
	god->number_of_mutex = i;
	if (pthread_mutex_init(&god->forks.mutex[i], NULL))
		return (free_all(god), 0);
	god->brains[i].number_of_philos = god->infos[0];
	god->brains[i].alive = &god->living;
	god->brains[i].forks = &god->forks;
	god->brains[i].num = i;
	god->brains[i].times = god->times;
	god->brains[i].all_meals = &god->all_meals;
	god->brains[i].all_here = &god->all_here;
	god->brains[i].start_god = &god->start;
	god->brains[i].right_fork = &god->forks.mutex[i];
	god->brains[i].death = &god->death;
	if (i == 0)
		god->brains[i].left_fork = &god->forks.mutex[god->infos[0] - 1];
	else
		god->brains[i].left_fork = &god->forks.mutex[i - 1];
	return (1);
}

int	create_mutex(t_philo *god)
{
	int	i;

	god->brains = (t_thinker *)not_calloc(god->infos[0], sizeof(t_thinker));
	god->forks.mutex = (t_mutex *)not_calloc(god->infos[0], sizeof(t_mutex));
	if (!god->brains || !god->forks.mutex)
		return (free_all(god), 0);
	i = -1;
	god->living = -1;
	while (++i < god->infos[0])
		if (!set_brains(god, i))
			return (0);
	god->print_mutex = pthread_mutex_init(&god->forks.print, NULL);
	god->alive_mutex = pthread_mutex_init(&god->forks.live, NULL);
	god->done_mutex = pthread_mutex_init(&god->forks.done, NULL);
	pthread_mutex_init(&god->forks.start, NULL);
	pthread_mutex_init(&god->forks.here, NULL);
	if (god->print_mutex || god->alive_mutex || god->done_mutex)
		return (free_all(god), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	god;

	memset(&god, 0, sizeof(god));
	if (!check_in(argc, argv, &god))
		return (1);
	if (!set_routine(&god))
		return (1);
	if (!create_mutex(&god))
		return (1);
	if (!create_thread(&god))
		return (1);
	free_all(&god);
	return (0);
}
