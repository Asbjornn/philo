/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:08:20 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/15 09:44:13 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void init_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->arg.nb_philo)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->forks[i].id = i;
		i++;
	}
}

void init_philo(t_table *table)
{
	int i;

	i = 0;
	while (i < table->arg.nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].left_fork = &table->forks[i].fork;
		table->philos[i].right_fork = &table->forks[(i + 1) % table->arg.nb_philo].fork;
		table->philos[i].table = table;
		table->philos[i].nb_eat = 0;
		table->philos[i].last_time_eat = 0;
		i++;
	}
}

void    init_table(t_table *table)
{
	table->forks = malloc(sizeof(t_fork *) * table->arg.nb_philo);
	if (!table->forks)
		return ;
	table->philos = malloc(sizeof(t_philo *) * table->arg.nb_philo);
	if (!table->philos)
	{
		free(table->forks);
		return ;
	}
	init_fork(table);
	init_philo(table);
}
