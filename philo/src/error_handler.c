/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:53:25 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/04 02:14:02 by mkettab          ###   ########.fr       */
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