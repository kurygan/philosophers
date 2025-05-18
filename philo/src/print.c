/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:31:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/06 00:11:44 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(t_philo *philo, char *status)
{
	printf("%lu %d %s\n", get_time() - philo->dinner->time_started, philo->id,
		status);
}

void	get_status(t_philo *philo, t_status stage)
{
	pthread_mutex_lock(&philo->dinner->write_lock);
	if (philo->dinner->dead == true && stage != DIED)
	{
		pthread_mutex_unlock(&philo->dinner->write_lock);
		return ;
	}
	if (stage == DIED)
		write_status(philo, "died");
	else if(stage == EATING)
		write_status(philo, "is eating");
	else if(stage == THINKING)
		write_status(philo, "is thinking");
	else if(stage == SLEEPING)
		write_status(philo, "is sleeping");
	else if(stage == GOT_FORK)
		write_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->dinner->write_lock);
}