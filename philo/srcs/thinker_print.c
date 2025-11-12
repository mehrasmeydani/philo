/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinker_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:37:58 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:53:14 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	thinker_print(t_thinker *philo, t_ui time, int num,
	const char *action)
{
	ml(&philo->forks->live);
	if ((my_time() - philo->last_meal) > philo->times.life + 9)
		return (*philo->alive = philo->num, *philo->death = my_time(), mu(&philo->forks->live), 1);
	if (*philo->alive != -1)
		return (mu(&philo->forks->live), 1);
	printf("%u %d %s\n", (my_time() - time) / 10, num, action);
	mu(&philo->forks->live);
	return (0);
}
