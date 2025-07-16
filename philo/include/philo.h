/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:54 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/16 15:29:16 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  INCULDES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCTURES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

# define NB_MAX_PHILO 200

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}		t_fork;

typedef struct s_arguments
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_times;
}		t_arguments;

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				nb_eat;
	int				last_time_eat;
	int				die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}		t_philo;

typedef struct s_table
{
	long		start_dinner_time;
	int			dinner;
	t_arguments	arg;
	t_philo		*philos;
	t_fork		*forks;
	pthread_t	supervisor;
}		t_table;

typedef enum e_state
{
	EAT = 0,
	SLEEP,
	THINK,
	LEFT_FORK,
	RIGHT_FORK,
	DEAD
}		t_state;

typedef enum e_error
{
	FORMAT = 0,
	ARGUMENT,
	VALUE
}		t_error;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STATES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	state_eat(t_philo *philo);
void	state_sleep(t_philo *philo);
void	state_think(t_philo *philo);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DINNER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	start_dinner(t_table *table);
void	end_dinner(t_table *table);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ROUTINE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	*routine(void *data);
void	*alone_routine(void *data);
void	*supervisor(void *data);
int		check_dead(t_philo *philo);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WRITE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	write_status(t_philo philo, t_state state);
int		write_error(t_error error);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INIT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	init_table(t_table *table);
void	init_fork(t_table *table);
void	init_philo(t_table *table);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TIME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int		get_time(void);
void	better_usleep(int time, t_table *table, t_philo *philo);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int		ft_atoi(char *line);
int		ft_strlen(char *line);
int		parse_arg(char *argv[]);

#endif