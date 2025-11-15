/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:52:36 by megardes          #+#    #+#             */
/*   Updated: 2025/11/15 12:36:40 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*start(void *in)
{
	t_thinker	*philo;

	philo = (t_thinker *)in;
	philo->start = 1;
	ml(&philo->forks->here);
	*philo->all_here = *philo->all_here + 1;
	mu(&philo->forks->here);
	while (true)
	{
		ml(&philo->forks->start);
		if (*philo->start_god)
		{
			philo->first = *philo->start_god;
			mu(&philo->forks->start);
			if (philo->num % 2 == 1)
				usleep(10);
			philo->last_meal = my_time();
			break ;
		}
		mu(&philo->forks->start);
		usleep(10);
	}
	return (philo->f(philo));
}

void	god_put_mutex(t_philo *god)
{
	mu(&god->forks.start);
	mu(&god->forks.live);
	mu(&god->forks.here);
}

void	god_start(t_philo *god)
{
	while (true)
	{
		ml(&god->forks.here);
		ml(&god->forks.live);
		if (god->living != 1)
		{
			ml(&god->forks.start);
			god->start = my_time();
			while (!god->start)
				god->start = my_time();
			god_put_mutex(god);
			break ;
		}
		mu(&god->forks.live);
		if (god->all_here == (t_ui)god->infos[0])
		{
			ml(&god->forks.start);
			god->start = my_time();
			mu(&god->forks.start);
			mu(&god->forks.here);
			break ;
		}
		mu(&god->forks.here);
		usleep(1);
	}
}
