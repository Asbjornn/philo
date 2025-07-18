/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:05:25 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/18 11:43:47 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	check_dead(t_philo *philo)
{
	long int	last_eat;
	long int	time_to_die;
	long int	now;

	now = get_time() - philo->table->start_dinner_time;
	last_eat = philo->last_time_eat;
	time_to_die = philo->table->arg.time_die;
	if (now - last_eat > time_to_die)
	{
		philo->die = 1;
		// philo->table->dinner = 1;
		return (1);
	}
	return (0);
}

int	check_full(t_philo *philo)
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
		printf("=== philo [%d] is full at [%ld] ===\n", philo->id, time);
		return (1);
	}
	else
		return (0);
}
