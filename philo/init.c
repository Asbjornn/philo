/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:08:20 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/18 11:59:23 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void	get_forks(t_philo *philo, t_table *t, int i)
{
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &t->forks[i].fork;
		philo->left_fork = &t->forks[(i + 1) % t->arg.nb_philo].fork;
	}
	else
	{
		philo->right_fork = &t->forks[(i + 1) % t->arg.nb_philo].fork;
		philo->left_fork = &t->forks[i].fork;
	}
}

void	init_fork(t_table *table)
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

void	init_philo(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->arg.nb_philo)
	{
		t->philos[i].id = i + 1;
		t->philos[i].table = t;
		t->philos[i].nb_eat = 0;
		t->philos[i].last_time_eat = 0;
		t->philos[i].die = 0;
		t->philos[i].out = 0;
		get_forks(&t->philos[i], t, i);
		i++;
	}
}

void	init_table(t_table *table)
{
	table->forks = malloc(sizeof(t_fork) * table->arg.nb_philo);
	if (!table->forks)
		return ;
	table->philos = malloc(sizeof(t_philo) * table->arg.nb_philo);
	if (!table->philos)
	{
		free(table->forks);
		return ;
	}
	table->dinner = 0;
	init_fork(table);
	init_philo(table);
}
