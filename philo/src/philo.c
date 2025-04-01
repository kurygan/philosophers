/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:35:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/01 17:45:04 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_global	dinner;

	if (ac != 5 || ac != 6)
		return(fprintf(stderr, "Error: Number of Args"), 0);
	memset(&dinner, 0, sizeof(t_global));
}