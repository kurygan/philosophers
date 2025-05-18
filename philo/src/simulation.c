/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:15:15 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/18 17:01:24 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	start_simulation(t_global *dinner)
{
	int	i;

	dinner->time_started = get_time() + (dinner->philo_nb * 50);
	i = 0;
	while (i < dinner->philo_nb)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, &r_philo,
				&dinner->philo[i]))
			return (error_failure(THREAD_ERR, dinner, 0));
		i++;
	}
	if (dinner->philo_nb > 1)
		if (pthread_create(&dinner->grim_reaper, NULL, &grim_reaper, dinner))
			return (error_failure(THREAD_ERR, dinner, 0));
	return (true);
}

void	stop_simulation(t_global *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->philo_nb)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	if (dinner->philo_nb > 1)
		pthread_join(dinner->grim_reaper, NULL);
	destroy_mutexes(dinner);
	free(dinner->philo);
	free(dinner);
}

bool	has_died(t_global *dinner)
{
	pthread_mutex_lock(&dinner->dead_lock);
	if (dinner->dead == true)
	{
		pthread_mutex_unlock(&dinner->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&dinner->dead_lock);
	return (false);
}
