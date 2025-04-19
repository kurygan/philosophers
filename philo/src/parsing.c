/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:22 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/19 02:44:42 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	parse_args(int ac, char **av, t_global *dinner)
{
	dinner->philo_numbers = ft_atoi(av[1]);
	dinner->time_to_die = ft_atoi(av[2]);
	dinner->time_to_eat = ft_atoi(av[3]);
	dinner->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		dinner->max_meals = ft_atoi(av[5]);
		if (dinner->max_meals == 0)
			return (error(POS_ERROR), false);
	}
	if (dinner->philo_numbers <= 1 || dinner->time_to_die == 0
		|| dinner->time_to_eat == 0 || dinner->time_to_sleep == 0)
		return (error(POS_ERROR), false);
	dinner->philo = malloc(dinner->philo_numbers * sizeof(t_philo));
	if (!dinner->philo)
		return (error(ALLOC_F), false);
	dinner->alive = true;
	philo_init(dinner);
	thread_init(dinner);
	return (true);
}

bool	philo_init(t_global *dinner)
{
	int	i;
	t_philo *temp;

	temp = dinner->philo;
	i = 0;
	if (pthread_mutex_init(&dinner->lock_dead, NULL))
		return (error(MUTEX_E), false);
	if (pthread_mutex_init(&dinner->lock_meal, NULL))
		return (error(MUTEX_E), false);
	if (pthread_mutex_init(&dinner->lock_write, NULL))
		return (error(MUTEX_E), false);
	while (i < dinner->philo_numbers)
	{
		memset(&temp[i], 0, sizeof(t_philo));
		if (pthread_mutex_init(&temp->fork, NULL))
			return (error(MUTEX_E), false);
		if (i > 0)
			temp[i].l_fork = &temp[i - 1].fork;
		temp[i].philo_id = i + 1;
		temp[i].dinner  = dinner;
		i++;
	}
	temp[0].l_fork = &temp[i - 1].fork;
	return (true);
}

bool	thread_init(t_global *dinner)
{
	int	i;

	i = 0;
	if (pthread_create(&dinner->monitor, NULL, &monitor_routine, dinner))
		return (error(THREAD_E), false);
	printf("Monitor Thread Created\n");
	while (i < dinner->philo_numbers)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL,
				&philo_routine, &dinner->philo))
			return (error(THREAD_E), false);
		i++;
	}
	printf("-----\n");
	return (true);
}