/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:17:58 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/05 21:53:49 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_failure(char *error_phrase, t_global *dinner, int nb)
{
	if (dinner->philo)
		free(dinner->philo);
	if (dinner)
	{
		free(dinner);
		dinner = NULL;
	}
	printf("Error: %s\n", error_phrase);
	return (nb);
}

void	*error_null(char *error_phrase, t_global *dinner)
{
	if (dinner->philo)
		free(dinner->philo);
	if (dinner)
	{
		free(dinner);
		dinner = NULL;
	}
	printf("Error: %s\n", error_phrase);
	return (NULL);
}

void	destroy_mutexes(t_global* dinner)
{
	int i;

	i = 0;
	while (i < dinner->philo_nb)
	{
		pthread_mutex_destroy(&dinner->philo[i].r_fork);
		i++;
	}
	pthread_mutex_destroy(&dinner->dead_lock);
	pthread_mutex_destroy(&dinner->meal_lock);
	pthread_mutex_destroy(&dinner->dead_lock);
}