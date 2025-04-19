/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:46:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/19 02:44:04 by mkettab          ###   ########.fr       */
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
	if (*str == '+' && str[1])
		str++;
	while (*str >= '0' && *str <= '9')
	{
		index = *str - '0';
		nbr = (nbr * 10) + index;
		str++;
	}
	if (*str)
		return(error(ARGS_N_VALID), 0);
	nbr = nbr * sign;
	if (nbr > INT_MAX)
		error(OVERFLOW_ERR);
	return ((int)nbr);
}

unsigned long	get_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}