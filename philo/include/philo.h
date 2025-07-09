/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:15:54 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 11:02:05 by gcauchy          ###   ########.fr       */
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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~  STRUCTURES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct 	s_arguments
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	eat_times;
}		t_arguments;

typedef struct	s_philo
{
	pthread_t	thread;
	int			id;
	int			fork;
}		t_philo;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STATES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void    state_eat(int time);
void    state_sleep(int time);
void    state_think(int time);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int ft_atoi(char *line);
int	ft_strlen(char *line);
int	parse_arg(char *argv[]);

#endif