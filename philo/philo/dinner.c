/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:05:51 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 13:51:51 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	table->start_dinner_time = get_time();
	if (table->arg.nb_philo == 1)
		pthread_create(&table->philos[i].thread, NULL,
			alone_routine, &table->philos[i]);
	else
	{
		while (i < table->arg.nb_philo)
		{
			pthread_create(&table->philos[i].thread, NULL,
				routine, &table->philos[i]);
			i++;
		}
		pthread_create(&table->supervisor, NULL, supervisor, table);
	}
	set_start(table, 1);
	pthread_create(&table->logger_thread, NULL, logger, table);
}

void	end_dinner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->arg.nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	if (table->arg.nb_philo > 1)
		pthread_join(table->supervisor, NULL);
	i = 0;
	while (i < table ->arg.nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->philos[i].mutex_data);
		i++;
	}
	pthread_join(table->logger_thread, NULL);
	pthread_mutex_destroy(&table->logger->mutex);
	pthread_mutex_destroy(&table->dinner_mutex);
	free(table->forks);
	free(table->philos);
	free(table->logger);
}
