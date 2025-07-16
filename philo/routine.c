/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:53:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/16 09:17:14 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// Comment arreter la routine peut importe le moment quand un philo meurt ?
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->die && philo->table->dinner == 0)
	{
		state_eat(philo);
		if (philo->nb_eat >= philo->table->arg.eat_times
			&& philo->table->arg.eat_times != -1)
		{
			printf("=== philo [%d] is full ===\n", philo->id);
			break ;
		}
		state_sleep(philo);
		state_think(philo);
		if (get_time() - philo->table->start_dinner_time
			> philo->last_time_eat + philo->table->arg.time_die)
		{
			write_message((*philo), DEAD);
			philo->die = 1;
			break ;
		}
	}
	return (NULL);
}

void	*supervisor(void *data)
{
	t_table	*table;
	int		i;
	
	printf("=== SUPERVISOR IS UP ===\n");
	table = (t_table*)data;
	while (1)
	{
		better_usleep(50);
		i = 0;
		while (i < table->arg.nb_philo)
		{
			if (table->philos[i].die == 1)
			{
				printf("=== philo %d is dead ===\n", i + 1);
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
