/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:00:40 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:44:35 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*my_eat(t_thinker *philo)
{
	if (!take_fork(philo))
		return (NULL);
	philo->last_meal = my_time();
	if (thinker_print(philo, philo->first, philo->num, "is eating"))
		return (mu(philo->right_fork), mu(philo->left_fork), NULL);
	if (my_usleep(philo, philo->times.eat, philo->times.life, philo->last_meal))
		return (mu(philo->right_fork), mu(philo->left_fork), NULL);
	put_fork(philo);
	if (philo->times.must_eat != 0 && check_meals(philo))
		return (NULL);
	return (my_sleep(philo));
}

void	*my_sleep(t_thinker *philo)
{
	if (thinker_print(philo, philo->first, philo->num, "is sleeping"))
		return (NULL);
	if (my_usleep(philo, philo->times.sleep, philo->times.life,
			philo->last_meal))
		return (NULL);
	return (my_think(philo));
}

void	*my_think(t_thinker *philo)
{
	if (thinker_print(philo, philo->first, philo->num, "is thinking"))
		return (NULL);
	if (my_usleep(philo, philo->times.think, philo->times.life,
			philo->last_meal))
		return (NULL);
	return (my_eat(philo));
}

int	set_routine(t_philo *god)
{
	int	i;

	i = -1;
	god->philo_rout = (int *)not_calloc(god->infos[0], sizeof(int));
	if (!god->philo_rout)
		return (0);
	while (++i < god->infos[0])
		god->philo_rout[i] = i % 2;
	if (god->infos[0] % 2)
		god->philo_rout[i - 1] += 1;
	god->route[0] = my_eat;
	if (god->infos[0] % 2)
	{
		god->route[1] = my_think;
		god->route[2] = my_sleep;
	}
	else
	{
		god->route[2] = my_think;
		god->route[1] = my_sleep;
	}
	return (1);
}
