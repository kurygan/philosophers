/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:12:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/15 00:18:42 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	printf("Philosopher ID %d is running\n", philo->philo_id);
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_global *dinner = (t_global *)arg;

	printf("Monitor Thread %p is running\n", &dinner->monitor);
	return (NULL);
}