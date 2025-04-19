/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:16:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/04/19 04:30:09 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Macros
// -----------------------------------------------------------------------------

# define ARG_ERROR "./philo \"time_to_die\" \"time_to_eat\" \"time_to_sleep\" \
[number_of_times_each_philosopher_must_eat]"

// Structures
// -----------------------------------------------------------------------------

typedef struct s_global
{
	int				philo_nb;
	unsigned long	time_started;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				max_meals;
	pthread_t		grim_reaper;
}					t_global;

// Errors
// -----------------------------------------------------------------------------

int					error_failure(char *error_phrase);

#endif