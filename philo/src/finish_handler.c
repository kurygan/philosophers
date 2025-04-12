/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:53:25 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/12 00:06:03 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_putstr_fd(char *str, int fd, bool endl)
{
	while(*str)
		write(fd, str++, 1);
	if (endl == true)
		write(fd, "\n", 1);
}

void	error(char *str)
{
	ft_putstr_fd(str, 2, true);
	exit(1);
}

void	freeall(t_global *dinner)
{
	free(dinner->philo);
	dinner->philo = NULL;
}

void	thread_join(t_global *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->philo_numbers)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
}

void	mutex_destroyer(t_global *dinner, int i)
{
	if (&dinner->lock_dead)
		pthread_mutex_destroy(&dinner->lock_dead);
	if (&dinner->lock_meal)
		pthread_mutex_destroy(&dinner->lock_meal);
	if (&dinner->lock_write)
		pthread_mutex_destroy(&dinner->lock_write);
	while (i)
		pthread_mutex_destroy(&dinner->philo[--i].fork);
}