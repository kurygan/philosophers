/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:10:12 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/05/18 17:00:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	long	nbr;

	if (!str || !*str)
		return (0);
	nbr = 0;
	if (*str == '+' && str[1] != 0)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if (*str || nbr > INT_MAX)
		return (0);
	return ((int)nbr);
}

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	better_sleep(t_global *dinner, unsigned int sleep_time)
{
	unsigned long	wake_up_t;

	wake_up_t = get_time() + sleep_time;
	while (get_time() < wake_up_t)
	{
		if (has_died(dinner))
			break ;
		usleep(100);
	}
}

void	set_delay(unsigned long time)
{
	while (get_time() < time)
		continue ;
}
