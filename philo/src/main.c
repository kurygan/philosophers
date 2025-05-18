/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:16:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/18 17:01:07 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_global	*dinner;

	if (ac != 5 && ac != 6)
		return (error_failure(ARG_ERROR, NULL, 1));
	if (!valid_args(ac, av))
		return (error_failure(NUM_ERROR, NULL, 1));
	dinner = dinner_init(ac, av);
	if (!dinner)
		return (1);
	if (!start_simulation(dinner))
		return (1);
	stop_simulation(dinner);
	return (0);
}
