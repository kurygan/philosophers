/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/30 09:08:57 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*lone_philo_r(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	get_status(philo, GOT_FORK);
	better_sleep(philo->dinner, philo->dinner->time_to_die);
	get_status(philo, DIED);
	pthread_mutex_unlock(&philo->r_fork);
	return (NULL);
}

void	think_r(t_philo *philo, bool print)
{
	long	time_to_think;
	
	pthread_mutex_lock(&philo->meal_lock);
	time_to_think = (philo->dinner->time_to_die 
			- (get_time() - philo->last_meal) - philo->dinner->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 600)
		time_to_think = 200;
	if (print == true)
		get_status(philo, THINKING);
	better_sleep(&philo->dinner, (unsigned long)time_to_think);
}

void	take_fork_order(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->l_fork);
		get_status(philo, GOT_FORK);
		pthread_mutex_lock(&philo->r_fork);
		get_status(philo, GOT_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->r_fork);
		get_status(philo, GOT_FORK);
		pthread_mutex_lock(philo->l_fork);
		get_status(philo, GOT_FORK);
	}
}

void	eat_sleep_r(t_philo *philo)
{
	take_fork_order(philo);
	get_status(philo, EATING);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	better_sleep(philo->dinner, philo->dinner->time_to_eat);
	if (!(philo->dinner->dead))
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->time_eat++;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	get_status(philo, SLEEPING);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	better_sleep(philo->dinner, philo->dinner->time_to_sleep);
}

void*	r_philo(void* arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->dinner->time_started;
	pthread_mutex_unlock(&philo->last_meal);
	set_delay(philo->dinner->time_started);
	if (philo->dinner->time_to_die == 0)
		return (NULL);
	if (philo->dinner->philo_nb == 1)
		return(lone_philo_r(philo));
	if (philo->id % 2)
		think_r(philo, false);
	while (!(philo->dinner->dead))
	{
		eat_sleep_r(philo);
		think_r(philo, true);
	}
	return (NULL);
}