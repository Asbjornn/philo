/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:46:10 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 16:15:32 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	write_message(t_philo philo, t_state state)
{
	if (state == EAT)
		printf("[%d] [%d] is eating\n");
	if (state == SLEEP)
		printf("[%d] [%d] is sleeping\n");
	if (state == THINK)
		printf("[%d] [%d] is thinking\n");
	if (state == DEAD)
		printf("[%d] [%d] died\n");
}
