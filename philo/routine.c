/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:53:03 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/16 15:56:03 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	check_dead(t_philo *philo)
{
	long int	dinner_start;
	long int	last_eat;
	long int	time_to_die;
	long int	time_to_eat;

	dinner_start = philo->table->start_dinner_time;
	last_eat = philo->last_time_eat;
	time_to_die = philo->table->arg.time_die;
	time_to_eat = philo->table->arg.time_eat;
	if (get_time() - dinner_start < last_eat + time_to_eat)
		return (0);
	if (get_time() - dinner_start > last_eat + time_to_die)
	{
		philo->die = 1;
		return (1);
	}
	return (0);
}

static int	check_full(t_philo *philo)
{
	int			nb_eat;
	int			eat_times;
	long int	time;

	nb_eat = philo->table->arg.eat_times;
	eat_times = philo->nb_eat;
	time = get_time() - philo->table->start_dinner_time;
	if (nb_eat == -1)
		return (0);
	if (eat_times >= nb_eat)
	{
		printf("=== philo [%d] is full ", philo->id);
		printf("at [%ld] ===\n", time);
		return (1);
	}
	else
		return (0);
}

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
	while (!philo->die && philo->table->dinner == 0)
	{
		state_eat(philo);
		if (check_full(philo) || check_dead(philo) || philo->table->dinner)
			break ;
		state_sleep(philo);
		if (check_full(philo) || check_dead(philo) || philo->table->dinner)
			break ;
		state_think(philo);
		if (check_full(philo) || check_dead(philo) || philo->table->dinner)
			break ;
	}
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
		better_usleep(10, table, NULL);
		i = 0;
		while (i < table->arg.nb_philo)
		{
			if (table->philos[i].die == 1)
			{
				printf("=== philo %d is dead ===\n", i + 1);
				write_status(table->philos[i], DEAD);
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
