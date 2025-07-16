/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:46:10 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/16 10:21:01 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	write_status(t_philo philo, t_state state)
{
	long	elapsed;

	elapsed = get_time() - philo.table->start_dinner_time;
	if (state == EAT)
		printf("%ld %d is eating\n", elapsed, philo.id);
	if (state == SLEEP)
		printf("%ld %d is sleeping\n", elapsed, philo.id);
	if (state == THINK)
		printf("%ld %d is thinking\n", elapsed, philo.id);
	if (state == DEAD)
		printf("%ld %d died\n", elapsed, philo.id);
	if (state == LEFT_FORK)
		printf("%ld %d has taken a fork\n", elapsed, philo.id);
	if (state == RIGHT_FORK)
		printf("%ld %d has taken a fork\n", elapsed, philo.id);
}

int	write_error(t_error error)
{
	if (error == FORMAT)
	{
		printf("format: ./philo 'nb_philo' 'time_die' ");
		printf("'time_eat' 'time_sleep' <optinal>'limit_eat_nb'\n");
	}
	else if (error == ARGUMENT)
		printf("Arguments must be ONLY positive int\n");
	else if (error == VALUE)
		printf("Value of argument arent resonable\n");
	return (1);
}
