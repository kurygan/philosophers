/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:08:02 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/05/18 17:01:10 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	valid_args(int ac, char **av)
{
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[2]) == 0 || ft_atoi(av[3]) == 0
		|| ft_atoi(av[4]) == 0)
		return (false);
	if (ac == 6)
		if (ft_atoi(av[5]) == 0)
			return (false);
	return (true);
}

t_philo	*init_philo(t_global *dinner)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * dinner->philo_nb);
	if (!philo)
		return (error_null(MALLOC_ERR, dinner));
	i = 0;
	while (i < dinner->philo_nb)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].id = i + 1;
		philo[i].dinner = dinner;
		philo[i].time_eat = 0;
		if (pthread_mutex_init(&philo[i].r_fork, NULL))
			return (error_null(MUTEX_ERR, dinner));
		if (pthread_mutex_init(&philo[i].meal_lock, NULL))
			return (error_null(MUTEX_ERR, dinner));
		if (i > 0)
			philo[i].l_fork = &philo[i - 1].r_fork;
		i++;
	}
	if (dinner->philo_nb > 1)
		philo[0].l_fork = &philo[i - 1].r_fork;
	return (philo);
}

bool	init_global_mutex(t_global *dinner)
{
	if (pthread_mutex_init(&dinner->dead_lock, NULL))
		return (error_failure(MUTEX_ERR, dinner, 0));
	if (pthread_mutex_init(&dinner->write_lock, NULL))
		return (error_failure(MUTEX_ERR, dinner, 0));
	return (true);
}

t_global	*dinner_init(int ac, char **av)
{
	t_global	*dinner;

	dinner = malloc(sizeof(t_global));
	if (!dinner)
		return (error_null(MALLOC_ERR, NULL));
	memset(dinner, 0, sizeof(t_global));
	dinner->philo_nb = ft_atoi(av[1]);
	dinner->time_to_die = ft_atoi(av[2]);
	dinner->time_to_eat = ft_atoi(av[3]);
	dinner->time_to_sleep = ft_atoi(av[4]);
	dinner->max_meals = -1;
	dinner->dead = false;
	if (ac == 6)
		dinner->max_meals = ft_atoi(av[5]);
	dinner->philo = init_philo(dinner);
	if (!dinner->philo)
		return (NULL);
	if (!init_global_mutex(dinner))
		return (NULL);
	return (dinner);
}
