/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:36:33 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/24 15:18:52 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	add_log(t_logger *logger, t_philo *philo, int time, char *message)
{
	t_log	log;

	pthread_mutex_lock(&logger->mutex);
	log.timestamp = time;
	log.philo_id = philo->id;
	log.message = message;
	log.died = philo->die;
	logger->logs[logger->rear] = log;
	logger->rear = (logger->rear + 1) % NB_MAX_MESSAGE;
	logger->count++;
	pthread_mutex_unlock(&logger->mutex);
}

void	print_log(t_logger *logger)
{
	t_log	log;

	pthread_mutex_lock(&logger->mutex);
	if (logger->count <= 0)
	{
		pthread_mutex_unlock(&logger->mutex);
		return ;
	}
	log = logger->logs[logger->front];
	if (log.died)
		logger->stop = 1;
	printf("%d %d %s\n", log.timestamp, log.philo_id, log.message);
	logger->front = (logger->front + 1) % NB_MAX_MESSAGE;
	logger->count--;
	pthread_mutex_unlock(&logger->mutex);
}
