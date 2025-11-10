/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:41:28 by megardes          #+#    #+#             */
/*   Updated: 2025/11/08 21:55:08 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

t_ui	my_time(void)
{
	t_tm	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((t_ui)time.tv_usec / 100 + (time.tv_sec % 100000 * 10000));
}
