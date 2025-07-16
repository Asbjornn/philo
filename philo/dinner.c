/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:05:51 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/15 17:10:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	table->start_dinner_time = get_time();
	while (i < table->arg.nb_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		i++;
	}
    pthread_create(&table->supervisor, NULL, supervisor, table);
}

void	end_dinner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table ->arg.nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
    table->dinner = 1;
    pthread_join(table->supervisor, NULL);
	i = 0;
	while (i < table ->arg.nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	free(table->forks);
	free(table->philos);
}
