/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:05:25 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/25 11:14:40 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	check_dead(t_philo *philo)
{
	long int	last_eat;
	long int	time_to_die;
	long int	now;

	pthread_mutex_lock(&philo->mutex_data);
	now = get_time() - philo->table->start_dinner_time;
	last_eat = philo->last_time_eat;
	time_to_die = philo->table->arg.time_die;
	pthread_mutex_unlock(&philo->mutex_data);
	if (now - last_eat > time_to_die)
	{
		set_die(philo, 1);
		return (1);
	}
	return (0);
}

int	check_full(t_philo *philo)
{
	int			nb_eat;
	int			eat_times;
	long int	time;

	pthread_mutex_lock(&philo->mutex_data);
	nb_eat = philo->table->arg.eat_times;
	eat_times = philo->nb_eat;
	time = get_time() - philo->table->start_dinner_time;
	pthread_mutex_unlock(&philo->mutex_data);
	if (nb_eat == -1)
		return (0);
	if (eat_times >= nb_eat)
	{
		// printf("=== philo [%d] is full at [%ld] ===\n", philo->id, time);
		return (1);
	}
	else
		return (0);
}

int	check_all_full(t_table *t)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	pthread_mutex_lock(&t->dinner_mutex);
	max = t->arg.nb_philo;
	pthread_mutex_unlock(&t->dinner_mutex);
	while (i < max)
	{
		if (get_out(&t->philos[i]))
			count++;
		i++;
	}
	if (count == max)
		return (1);
	return (0);
}
