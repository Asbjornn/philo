/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:53:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/17 16:09:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*alone_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	write_status((*philo), LEFT_FORK);
	better_usleep(philo->table->arg.time_die, philo->table, philo);
	write_status((*philo), DEAD);
	return (NULL);
}

// Comment arreter la routine peut importe le moment quand un philo meurt ?
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		better_usleep(philo->table->arg.time_eat, philo->table, NULL);
	while (!philo->die && !philo->table->dinner)
	{
		state_eat(philo);
		if (check_full(philo) || philo->table->dinner)
			break ;
		state_sleep(philo);
		if (check_full(philo) || philo->table->dinner)
			break ;
		state_think(philo);
		if (check_full(philo) || philo->table->dinner)
			break ;
	}
	philo->out = 1;
	return (NULL);
}

void	*supervisor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	better_usleep(5, table, NULL);
	printf("=== SUPERVISOR IS UP ===\n");
	while (1)
	{
		i = 0;
		while (i < table->arg.nb_philo)
		{
			if (check_dead(&table->philos[i]) && !table->philos[i].out)
			{
				write_death(table->philos[i]);
				table->dinner = 1;
				break ;
			}
			i++;
		}
		if (table->dinner)
			break ;
	}
	printf("=== SUPERVISOR IS DOWN ===\n");
	return (NULL);
}
