/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:35:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/02 21:10:45 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_global	dinner;

	if (ac != 5 && ac != 6)
		return (error(ARGS_N_VALID), 1);
	memset(&dinner, 0, sizeof(t_global));
	parse_args(ac, av, &dinner);

	printf("Philo numbers: %d\nTime to Die: %d\nTime to Eat: %d\nTime to sleep: %d\nMax Meals: %d\n", dinner.philo_numbers, dinner.time_to_die, dinner.time_to_eat, dinner.time_to_sleep, dinner.max_meals);
}
