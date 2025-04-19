/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:35:51 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/04/15 00:37:257 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define ARGS_NB_ERR "Error: Put a Valid Number of Arguments"
# define ARGS_N_VALID "Error: Put Valid Arguments"
# define OVERFLOW_ERR "Error: Numbers are too Big for this One"
# define POS_ERROR "Error: Put Positive Numbers only"
# define ALLOC_F "Error: Malloc Failed"
# define THREAD_E "Error: Thread Creation Failed"
# define MUTEX_E "Error: Mutex Creation Failed"

typedef struct s_global
{
	int				philo_numbers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	bool			alive;
	size_t			time_started;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_meal;
	pthread_t		monitor;
	struct s_philo	*philo;
}					t_global;

typedef struct s_philo
{
	int				philo_id;
	int				t_eaten;
	pthread_t		thread;
	unsigned long	last_meal_time;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	lock_t_eaten;
	t_global		*dinner;
}					t_philo;

bool				parse_args(int ac, char **av, t_global *dinner);
void				error(char *str);
void				ft_putstr_fd(char *str, int fd, bool endl);
int					ft_atoi(char *str);
bool				philo_init(t_global *dinner);
void				freeall(t_global *dinner);
bool				thread_init(t_global *dinner);
void				thread_join(t_global *dinner);
unsigned long		get_time(void);
void				*philo_routine(void *arg);
void				*monitor_routine(void *arg);
void				mutex_dest(t_global *dinner, int i);

#endif