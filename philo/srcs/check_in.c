/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megardes <megardes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:31:31 by megardes          #+#    #+#             */
/*   Updated: 2025/11/12 01:47:04 by megardes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	set_invalid(t_philo *god)
{
	const t_ui	sleep = god->times.sleep;
	const t_ui	eat = god->times.eat;
	const t_ui	life = god->times.life;

	if (god->infos[0] % 2)
	{
		if (life - eat <= eat + sleep)
			god->times.think = life;
	}
	else
	{
		if (life == eat + sleep)
			god->times.think = life + 10;
	}
}

static void	set_think(t_philo *god)
{
	if (god->infos[0] % 2)
	{
		if (god->times.eat <= god->times.sleep)
		{
			god->times.think = (god->times.eat * 2 - god->times.sleep)
				* (god->times.eat * 2 > god->times.sleep) / 2;
		}
		else
			god->times.think = (god->times.eat - god->times.sleep)
				* 3 / 2;
	}
	else
	{
		god->times.think = god->times.eat - god->times.sleep + 1;
	}
}

int	check_in(int argc, char **argv, t_philo *god)
{
	god->infos[4] = -1;
	if (argc < 5)
		return (ft_put_endl("Not enough arguments", 2), 0);
	while (--argc > 0)
	{
		if (((argv[argc][0] != '+' || argv[argc]++) && !ft_isdigit(argv[argc]))
			|| argv[argc][0] == '0')
			return (ft_put_str("Argument ", 2), ft_putnbr(argc, 2),
				ft_put_endl(": is not a valid number", 2), 0);
		else
			god->infos[argc - 1] = not_atoi(argv[argc]);
	}
	god->times.life = god->infos[1] * 10;
	god->times.eat = god->infos[2] * 10;
	god->times.sleep = god->infos[3] * 10;
	set_think(god);
	set_invalid(god);
	if (god->infos[4] != -1)
		god->times.must_eat = god->infos[4];
	return (1);
}
