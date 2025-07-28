/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:41:02 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/28 13:48:52 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	get_dinner(t_table *t)
{
	int	value;

	pthread_mutex_lock(&t->dinner_mutex);
	value = t->dinner;
	pthread_mutex_unlock(&t->dinner_mutex);
	return (value);
}

int	get_start(t_table *t)
{
	int	value;

	pthread_mutex_lock(&t->dinner_mutex);
	value = t->can_start;
	pthread_mutex_unlock(&t->dinner_mutex);
	return (value);
}

int	get_die(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->mutex_data);
	value = philo->die;
	pthread_mutex_unlock(&philo->mutex_data);
	return (value);
}

int	get_out(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->mutex_data);
	value = philo->out;
	pthread_mutex_unlock(&philo->mutex_data);
	return (value);
}
