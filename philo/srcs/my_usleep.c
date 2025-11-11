/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:46:06 by megardes          #+#    #+#             */
/*   Updated: 2025/11/11 19:58:06 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	my_usleep(t_thinker *philo, t_ui time, t_ui life,
	t_ui last_meal)
{
	t_ui	pass_time;
	size_t	i;

	pass_time = my_time();
	i = 0;
	while (my_time() - pass_time < time || life == time)
	{
		if (i % 50 == 0)
		{
			if (my_time() - last_meal > life + 9)
			{
				ml(&philo->forks->live);
				if (*philo->alive != -1)
					return (mu(&philo->forks->live), 1);
				*philo->alive = philo->num;
				mu(&philo->forks->live);
				return (1);
			}
		}
		i++;
		usleep(20);
	}
	return (0);
}
