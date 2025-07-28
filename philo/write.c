/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:46:10 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 12:33:49 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	write_status(t_philo *philo, t_state state)
{
	long	elapsed;

	pthread_mutex_lock(&philo->mutex_data);
	elapsed = get_time() - philo->table->start_dinner_time;
	pthread_mutex_unlock(&philo->mutex_data);
	if (get_dinner(philo->table))
		return ;
	if (state == EAT)
		add_log(philo->table->logger, philo, elapsed, "is eating");
	if (state == SLEEP)
		add_log(philo->table->logger, philo, elapsed, "is sleeping");
	if (state == THINK)
		add_log(philo->table->logger, philo, elapsed, "is thinking");
	if (state == DEAD)
		add_log(philo->table->logger, philo, elapsed, "died");
	if (state == LEFT_FORK)
		add_log(philo->table->logger, philo, elapsed, "has taken a fork");
	if (state == RIGHT_FORK)
		add_log(philo->table->logger, philo, elapsed, "has taken a fork");
}

int	write_error(t_error error)
{
	if (error == FORMAT)
	{
		printf("format: ./philo 'nb_philo' 'time_die' ");
		printf("'time_eat' 'time_sleep' <optinal>'limit_eat_nb'\n");
	}
	else if (error == ARGUMENT)
		printf("Arguments must be ONLY positive int\n");
	else if (error == VALUE)
		printf("Value of argument arent resonable\n");
	return (1);
}
