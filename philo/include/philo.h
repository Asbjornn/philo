/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:54 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/10 14:07:47 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  INCULDES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

# include <stdio.h>
# include <unistd.h>
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

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				nb_eat;
	int				last_time_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_arguments		*arg;
}		t_philo;

typedef enum e_state
{
	EAT = 0,
	SLEEP,
	THINK,
	DEAD
}		t_state;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STATES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	state_eat(int time, t_philo philo);
void	state_sleep(int time, t_philo philo);
void	state_think(int time, t_philo philo);
void	*routine(void *data);

void	write_message(t_philo philo, t_state state);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int		ft_atoi(char *line);
int		ft_strlen(char *line);
int		parse_arg(char *argv[]);
int		get_time(void);

#endif