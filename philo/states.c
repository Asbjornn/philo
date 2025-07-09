/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:22:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 16:19:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	state_eat(int time, t_philo philo)
{
	// printf("I'm in eat state and i wait [%d] milliseconds\n", time);
	write_message(philo, EAT);
	usleep(time);
}

void	state_sleep(int time, t_philo philo)
{
	long int	sleep_time;

	sleep_time = get_time() + time;
	while (get_time() < sleep_time)
	{
		usleep(100);
	}
	write_message(philo, SLEEP);
	// printf("I'm in sleep state and i waited [%ld] milliseconds\n", sleep_time);
}

void	state_think(int time, t_philo philo)
{
	// printf("I'm in think state and i wait [%d] milliseconds\n", time);
	write_message(philo, THINK);
	usleep(time);
}

void	*routine(void *data)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)data;
	printf("we are %d philos\n", philo->arg->nb_philo);
	i = 0;
	while (i < 3)
	{
		state_eat(philo->arg->time_eat, (*philo));
		state_sleep(philo->arg->time_sleep, (*philo));
		state_think(philo->arg->time_sleep + 100, (*philo));
		i++;
	}
	return (NULL);
}
