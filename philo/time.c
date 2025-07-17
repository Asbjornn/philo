/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:22:26 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/17 15:59:36 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	better_usleep(int time, t_table *table, t_philo *philo)
{
	long int	sleep_time;

	sleep_time = get_time() + time;
	while (get_time() < sleep_time)
	{
		if (philo)
		{
			if (check_dead(philo) == 1)
				break ;
		}
		if (table->dinner)
			break ;
		usleep(10);
	}
}
