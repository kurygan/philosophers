/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:53:25 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/09 20:39:31 by tylerlover9      ###   ########.fr       */
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