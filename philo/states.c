/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:22:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/15 16:22:45 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	better_usleep(int time)
{
	long int	sleep_time;

	sleep_time = get_time() + time;
	while (get_time() < sleep_time)
		usleep(100);
}

// take both fork
// eat and get the time 
// if no fork -> think until fork are back ?
void	state_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	write_message((*philo), LEFT_FORK);
	pthread_mutex_lock(philo->right_fork);
	write_message((*philo), RIGHT_FORK);
	write_message((*philo), EAT);
	philo->nb_eat ++;
	philo->last_time_eat = get_time() - philo->table->start_dinner_time;
	better_usleep(philo->table->arg.time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	state_sleep(t_philo *philo)
{
	write_message((*philo), SLEEP);
	better_usleep((*philo).table->arg.time_sleep);
}

// WHEN DO THE PHILO THINK ?????
void	state_think(t_philo *philo)
{
	write_message((*philo), THINK);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->die)
	{
		state_eat(philo);
		state_sleep(philo);
		state_think(philo);
		if (get_time() - philo->table->start_dinner_time
			> philo->last_time_eat + philo->table->arg.time_die)
		{
			write_message((*philo), DEAD);
			philo->die = 1;
		}
		if (philo->nb_eat >= philo->table->arg.eat_times)
			break ;
	}
	return (NULL);
}
