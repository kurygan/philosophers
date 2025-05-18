/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 04:16:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/05/06 23:49:25 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>

// Macros
// -----------------------------------------------------------------------------

# define ARG_ERROR "./philo \"time_to_die\" \"time_to_eat\" \"time_to_sleep\" \
[number_of_times_each_philosopher_must_eat]"
# define NUM_ERROR "Put only numbers between 1 and 2147483647"
# define MALLOC_ERR "Failed to Allocate Memory"
# define MUTEX_ERR "Failed to init mutex"
# define THREAD_ERR "Failed to init thread"
# define MAX_PHILO 200

// Structures
// -----------------------------------------------------------------------------

typedef struct s_philo	t_philo;

typedef struct s_global
{
	int				philo_nb;
	unsigned long	time_started;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				max_meals;
	bool			dead;
	pthread_t		grim_reaper;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philo;
}					t_global;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	unsigned long	last_meal;
	unsigned int	time_eat;
	t_global		*dinner;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef enum s_status
{
	DIED,
	SLEEPING,
	EATING,
	THINKING,
	GOT_FORK
}	t_status;

// Functions
// -----------------------------------------------------------------------------

int	error_failure(char *error_phrase, t_global *dinner, int nb);
int			ft_atoi(char *str);
bool		valid_args(int ac, char **av);
t_global*	dinner_init(int ac, char **av);
void		*error_null(char *str, t_global *dinner);
bool	has_died(t_global *dinner);
void	set_delay(unsigned long time);
void	get_status(t_philo *philo, t_status stage);
void	better_sleep(t_global *dinner, unsigned int sleep_time);
void*	r_philo(void* arg);
bool	start_simulation(t_global *dinner);
void	stop_simulation(t_global *dinner);
unsigned long	get_time(void);
void	destroy_mutexes(t_global* dinner);
void*	grim_reaper(void* arg);

#endif