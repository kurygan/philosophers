/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:49:42 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/09 11:29:37 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	need_kill(t_philo* philo)
{
	unsigned long	curr_time;

	curr_time = get_time();
	if ((curr_time - philo->last_meal) >= (unsigned long)philo->dinner->time_to_die)
	{
		pthread_mutex_lock(&philo->dinner->dead_lock);
		philo->dinner->dead = true;
		get_status(philo, DIED);
		pthread_mutex_unlock(&philo->dinner->dead_lock);
		pthread_mutex_unlock(&philo->meal_lock);
		return (true);
	}
	return (false);
}

bool	end_reached(t_global* dinner)
{
	int		i;
	bool all_eaten;

	i = 0;
	all_eaten = true;
	while(i < dinner->philo_nb)
	{
		pthread_mutex_lock(&dinner->philo[i].meal_lock);
		if (need_kill(&dinner->philo[i]))
			return (true);
		if (dinner->max_meals != -1 && dinner->philo[i].time_eat < (unsigned int)dinner->max_meals)
			all_eaten = false;
		pthread_mutex_unlock(&dinner->philo[i].meal_lock);
		i++;
	}
	if (all_eaten && dinner->max_meals != -1)
	{
		pthread_mutex_lock(&dinner->dead_lock);
		dinner->dead = true;
		pthread_mutex_unlock(&dinner->dead_lock);
		return (true);
	}
	return (false);
}

void*	grim_reaper(void* arg)
{
	t_global*	dinner;

	dinner = (t_global*)arg;
	set_delay(dinner->time_started);
	while (1)
	{
		if (end_reached(dinner))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}