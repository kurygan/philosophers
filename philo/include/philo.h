/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:35:51 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/02 21:17:06 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

# define ARGS_NB_ERR "Error: Put a Valid Number of Arguments"
# define ARGS_N_VALID "Error: Put Valid Arguments"
# define OVERFLOW_ERR "Error: Numbers are too Big for this One"
# define POS_ERROR "Error: Put Positive Numbers only"

typedef struct s_global
{
	bool			alive;
	int				philo_numbers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	size_t			time_started;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_meal;
	pthread_mutex_t	*forks;
}	t_global;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread;
	size_t			last_meal_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_global		*dinner;
}	t_philo;

void	parse_args(int ac, char **av, t_global *dinner);
void	error(char *str);
void	ft_putstr_fd(char *str, int fd, bool endl);
int		ft_atoi(char *str);

#endif