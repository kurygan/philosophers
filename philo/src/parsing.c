/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:46:22 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/07 23:03:42 by mkettab          ###   ########.fr       */
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
	while (i < dinner->philo_numbers)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, temp, &i) != 0)
			return (freeall(dinner), error(THREAD_E));
		i++;
	}
}

void	*temp(void *arg)
{
	int *i = (int *)arg;
	printf("Thread number %d created\n", *i);
	return NULL;
}