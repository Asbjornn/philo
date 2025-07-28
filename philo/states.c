/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:22:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 13:35:55 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	state_eat(t_philo *philo)
{
	if (get_dinner(philo->table) || get_die(philo))
		return ;
	pthread_mutex_lock(philo->left_fork);
	write_status(philo, LEFT_FORK);
	pthread_mutex_lock(philo->right_fork);
	write_status(philo, RIGHT_FORK);
	write_status(philo, EAT);
	pthread_mutex_lock(&philo->mutex_data);
	philo->last_time_eat = get_time() - philo->table->start_dinner_time;
	philo->nb_eat ++;
	pthread_mutex_unlock(&philo->mutex_data);
	better_usleep(philo->table->arg.time_eat, philo->table, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	state_sleep(t_philo *philo)
{
	if (get_dinner(philo->table) || get_die(philo))
		return ;
	write_status(philo, SLEEP);
	better_usleep((*philo).table->arg.time_sleep, philo->table, philo);
}

void	state_think(t_philo *philo)
{
	if (get_dinner(philo->table) || get_die(philo))
		return ;
	write_status(philo, THINK);
}
