/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:22 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/12 00:57:47 by mkettab          ###   ########.fr       */
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
		if (dinner->max_meals < 0)
			error(POS_ERROR);
	}
	if (dinner->philo_numbers < 1 || dinner->time_to_die < 0
		|| dinner->time_to_eat < 0 || dinner->time_to_sleep < 0)
		error(POS_ERROR);
	dinner->philo = malloc(dinner->philo_numbers * sizeof(t_philo));
	if (!dinner->philo)
		return (error(ALLOC_F));
	dinner->alive = true;
	philo_init(dinner);
	mutex_init(dinner);
	thread_init(dinner);
}

void	philo_init(t_global *dinner)
{
	int	i;
	t_philo *temp;

	temp = dinner->philo;
	i = 0;
	if (pthread_mutex_init(&dinner->lock_dead, NULL))
		return (freeall(dinner), error(MUTEX_E));
	if (pthread_mutex_init(&dinner->lock_meal, NULL))
		return (mutex_destroyer(dinner, i), freeall(dinner), error(MUTEX_E));
	if (pthread_mutex_init(&dinner->lock_write, NULL))
		return (mutex_destroyer(dinner, i), freeall(dinner), error(MUTEX_E));
	while (i < dinner->philo_numbers)
	{
		memset(&temp[i], 0, sizeof(t_philo));
		if (pthread_mutex_init(&temp->fork, NULL))
			return (mutex_destroyer(dinner, i), freeall(dinner), error(MUTEX_E));
		temp[i].philo_id = i + 1;
		temp[i].dinner  = dinner;
		i++;
	}
}

void	mutex_init(t_global *dinner)
{
	
}

void	thread_init(t_global *dinner)
{
	int	i;

	i = 0;
	if (pthread_create(&dinner->reaper, NULL, temp, NULL))
		return (freeall(dinner), error(THREAD_E));
	printf("Monitor Thread Created\n");
	while (i < dinner->philo_numbers)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, &philo_routine, NULL))
			return (freeall(dinner), error(THREAD_E));
		printf("Thread Philo ID: %d Created\n", i + 1);
		i++;
	}
	printf("-----\n");
}