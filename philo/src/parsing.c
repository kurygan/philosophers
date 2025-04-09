/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:22 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/09 20:38:01 by tylerlover9      ###   ########.fr       */
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
	philo_init(dinner);
	thread_init(dinner);
}

void	philo_init(t_global *dinner)
{
	int	i;
	t_philo *temp;

	temp = dinner->philo;
	i = 0;
	while (i < dinner->philo_numbers)
	{
		memset(&temp[i], 0, sizeof(t_philo));
		temp[i].philo_id = i + 1;
		temp[i].dinner  = dinner;
		temp[i].alive = true;
		i++;
	}
}

void	thread_init(t_global *dinner)
{
	int	i;

	i = 0;
	if (pthread_create(&dinner->monitor, NULL, temp, NULL))
		return (freeall(dinner), error(THREAD_E));
	printf("Monitor Thread Created\n");
	while (i < dinner->philo_numbers)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, temp, NULL))
			return (freeall(dinner), error(THREAD_E));
		printf("Thread Philo ID: %d Created\n", i + 1);
		i++;
	}
	printf("-----\n");
}

void	*temp()
{
	return NULL;
}