/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/07 00:20:04 by mkettab          ###   ########.fr       */
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

void	eat_sleep_r(t_philo *philo)
{
	//take_fork_order(philo);
	pthread_mutex_lock(&philo->r_fork);
	get_status(philo, GOT_FORK);
	pthread_mutex_lock(philo->l_fork);
	get_status(philo, GOT_FORK);
	get_status(philo, EATING);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	better_sleep(philo->dinner, philo->dinner->time_to_eat);
	if (!(philo->dinner->dead))
		philo->time_eat++;
	get_status(philo, SLEEPING);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	better_sleep(philo->dinner, philo->dinner->time_to_sleep);
	get_status(philo, THINKING);
}

void*	r_philo(void* arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->dinner->time_started;
	pthread_mutex_unlock(&philo->meal_lock);
	set_delay(philo->dinner->time_started);
	if (philo->dinner->time_to_die == 0)
		return (NULL);
	if (philo->dinner->philo_nb == 1)
		return(lone_philo_r(philo));
	if (philo->id % 2)
		usleep((philo->dinner->time_to_eat / 2) * 100);
	//int i = 0;
	while (!(philo->dinner->dead)){
		//if (i == 0)
		//	printf("%lu %d\n", get_time(), philo->id);
		eat_sleep_r(philo);
		//i++;
	}
	return (NULL);
}