/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:16:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/24 21:52:38 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_global *dinner;

	if (ac != 5 && ac != 6)
		return (error_failure(ARG_ERROR, NULL, 1));
	if (!valid_args(ac, av))
		return (error_failure(NUM_ERROR, NULL, 1));
	memset(dinner, 0, sizeof(t_global));
	dinner = dinner_init(ac, av);
	if (!dinner)
		return (1);
	return (0);
}
