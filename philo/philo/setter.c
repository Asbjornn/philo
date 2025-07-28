/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:44:57 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 13:49:11 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	set_dinner(t_table *t, int value)
{
	pthread_mutex_lock(&t->dinner_mutex);
	t->dinner = value;
	pthread_mutex_unlock(&t->dinner_mutex);
}

void	set_start(t_table *t, int value)
{
	pthread_mutex_lock(&t->dinner_mutex);
	t->can_start = value;
	pthread_mutex_unlock(&t->dinner_mutex);
}

void	set_die(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->mutex_data);
	philo->die = value;
	pthread_mutex_unlock(&philo->mutex_data);
}

void	set_out(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->mutex_data);
	philo->out = value;
	pthread_mutex_unlock(&philo->mutex_data);
}
