/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:46:10 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/15 09:42:08 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	write_message(t_philo philo, t_state state)
{
	long	elapsed;

	elapsed = get_time() - philo.table->start_dinner_time;
	if (state == EAT)
		printf("[%ld] [%d] is eating\n", elapsed, philo.id);
	if (state == SLEEP)
		printf("[%ld] [%d] is sleeping\n", elapsed, philo.id);
	if (state == THINK)
		printf("[%ld] [%d] is thinking\n", elapsed, philo.id);
	if (state == DEAD)
		printf("[%ld] [%d] died\n", elapsed, philo.id);
	if (state == LEFT_FORK)
		printf("[%ld] [%d] as take the left fork", elapsed, philo.id);
	if (state == RIGHT_FORK)
		printf("[%ld] [%d] as take the right fork", elapsed, philo.id);
}
