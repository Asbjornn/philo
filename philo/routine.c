/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:53:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 13:51:19 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*alone_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	write_status(philo, LEFT_FORK);
	better_usleep(philo->table->arg.time_die, philo->table, philo);
	write_status(philo, DEAD);
	set_dinner(philo->table, 1);
	set_die(philo, 1);
	set_out(philo, 1);
	return (NULL);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!get_start(philo->table))
		better_usleep(5, philo->table, philo);
	if (philo->id % 2 == 0)
		better_usleep(philo->table->arg.time_eat, philo->table, NULL);
	while (!get_die(philo) && !get_dinner(philo->table))
	{
		state_eat(philo);
		if (check_full(philo))
			break ;
		state_sleep(philo);
		state_think(philo);
	}
	set_out(philo, 1);
	return (NULL);
}

void	*supervisor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!get_dinner(table))
	{
		i = -1;
		while (++i < table->arg.nb_philo)
		{
			if (check_dead(&table->philos[i]) && !get_out(&table->philos[i]))
			{
				write_status(&table->philos[i], DEAD);
				set_die(&table->philos[i], 1);
				set_dinner(table, 1);
				break ;
			}
			if (check_all_full(table))
			{
				set_dinner(table, 1);
				break ;
			}
		}
		better_usleep(1, table, NULL);
	}
	return (NULL);
}

void	*logger(void *data)
{
	t_table		*table;
	t_logger	*logger;
	int			stop;
	int			count;

	table = (t_table *)data;
	logger = table->logger;
	while (1)
	{
		pthread_mutex_lock(&logger->mutex);
		count = logger->count;
		stop = logger->stop;
		pthread_mutex_unlock(&logger->mutex);
		if (stop)
			break ;
		if (!count)
		{
			if (get_dinner(table))
				break ;
			better_usleep(5, table, NULL);
		}
		else
			print_log(logger);
	}
	return (NULL);
}
