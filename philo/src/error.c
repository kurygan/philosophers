/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:17:58 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/24 21:51:39 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error_failure(char *error_phrase, t_global *dinner, int nb)
{
	if (dinner->philo)
		free(dinner->philo);
	if (dinner)
	{
		free(dinner);
		dinner = NULL;
	}
	printf("Error: %s\n", error_phrase);
	return (nb);
}

void	*error_null(char *str, t_global *dinner)
{
	if (dinner->philo)
		free(dinner->philo);
	if (dinner)
	{
		free(dinner);
		dinner = NULL;
	}
	printf("Error: %s\n", str);
	return (NULL);
}