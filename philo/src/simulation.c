/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:15:15 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/26 19:22:13 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	start_simulation(t_global *dinner)
{
	int i;

	dinner->time_started = get_time() + (dinner->philo_nb * 50);
	i = 0;
	while (i < dinner->philo_nb)
	{
		
	}
}

void	stop_simulation(t_global *dinner)
{
	
}

bool	has_died(t_global *dinner)
{
	pthread_mutex_lock(&dinner->dead_lock);
	if (dinner->dead = true)
	{
		pthread_mutex_unlock(&dinner->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&dinner->dead_lock);
	return (false);
}
