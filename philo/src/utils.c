/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:46:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/11 04:10:47 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	long	nbr;
	int		index;
	int		sign;

	sign = 1;
	nbr = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		index = *str - '0';
		nbr = (nbr * 10) + index;
		str++;
	}
	if (*str)
		error(ARGS_N_VALID);
	nbr = nbr * sign;
	if (nbr > INT_MAX || nbr < INT_MIN)
		error(OVERFLOW_ERR);
	return ((int)nbr);
}

int	get_time_in_usec(unsigned long *time)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	*time = tv.tv_sec * 1000000 + tv.tv_usec;
}