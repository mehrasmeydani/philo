/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:58:42 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:42:41 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_meals(t_thinker *philo)
{
	ml(&philo->forks->done);
	if (philo->meals < philo->times.must_eat)
	{
		philo->meals++;
		if (philo->meals == philo->times.must_eat)
			*(philo->all_meals) = *(philo->all_meals) + 1;
	}
	if (*philo->all_meals == philo->number_of_philos)
		return (mu(&philo->forks->done), 1);
	mu(&philo->forks->done);
	return (0);
}

int	god_mealcheck(t_philo *god)
{
	ml(&god->forks.done);
	if (god->all_meals == (t_ui)god->infos[0])
		return (mu(&god->forks.done), 1);
	mu(&god->forks.done);
	return (0);
}
