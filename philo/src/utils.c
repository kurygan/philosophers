/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:46:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/02 21:03:15 by tylerlover9      ###   ########.fr       */
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
