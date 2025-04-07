/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:35:47 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/04 02:12:21 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_debug(t_global *dinner)
{
	t_philo *temp = dinner->philo;
	int i = 0;
	printf("Philo Numbers: %d\n", dinner->philo_numbers);
	printf("Time to Die: %d\n", dinner->time_to_die);
	printf("Time to Eat: %d\n", dinner->time_to_eat);
	printf("Time to Sleep: %d\n", dinner->time_to_sleep);
	printf("Max Meals: %d\n\n", dinner->max_meals);
	while (i < dinner->philo_numbers)
	{
		printf("Philo Adress: %p\n", &temp[i]);
		printf("Philo ID: %d\n", temp[i].philo_id);
		printf("Philo Alive: %d\n", temp[i].alive);
		printf("-----\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_global	dinner;

	if (ac != 5 && ac != 6)
		return (error(ARGS_N_VALID), 1);
	memset(&dinner, 0, sizeof(t_global));
	parse_args(ac, av, &dinner);
	/*
		Innit Threads
		Innit Mutex
	*/
	print_debug(&dinner);
	freeall(&dinner);
}
