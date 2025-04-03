/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:22 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/02 21:14:08 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	parse_args(int ac, char **av, t_global *dinner)
{
	dinner->philo_numbers = ft_atoi(av[1]);
	dinner->time_to_die = ft_atoi(av[2]);
	dinner->time_to_eat = ft_atoi(av[3]);
	dinner->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		dinner->max_meals = ft_atoi(av[5]);
		if (dinner->max_meals < 1)
			error(POS_ERROR);
	}
	if (dinner->philo_numbers < 1 || dinner->time_to_die < 1
		|| dinner->time_to_eat < 1 || dinner->time_to_sleep < 1)
		error(POS_ERROR);
}
