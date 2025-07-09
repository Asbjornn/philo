/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:17:24 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 16:17:56 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static void	init_philos(t_arguments arg)
{
	t_philo			philos[NB_MAX_PHILO];
	pthread_mutex_t	fork[NB_MAX_PHILO];
	int				i;

	while (i < arg.nb_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < arg.nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].arg = &arg;
		philos[i].left_fork = &fork[i];
		philos[i].right_fork = &fork[(i + 1) % arg.nb_philo];
		i++;
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	}
	i = 0;
	while (i < arg.nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

static t_arguments	fill_arg( char *argv[], t_arguments *arg)
{
	arg->nb_philo = ft_atoi(argv[1]);
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		arg->eat_times = ft_atoi(argv[5]);
	else
		arg->eat_times = -1;
	return (*arg);
}

int	main(int argc, char *argv[])
{
	t_arguments	arg;

	if (argc < 5 || argc > 6)
		printf("format: ./philo 'nb_philo' 'time_die'\
			'time_eat' 'time_sleep'\n");
	else
	{
		if (parse_arg(argv) == 1)
			return (0);
		arg = fill_arg(argv, &arg);
		if (arg.nb_philo <= 0 || arg.time_die <= 0
			|| arg.time_eat <= 0 || arg.time_sleep <= 0)
			return (0);
		init_philos(arg);
	}
	return (0);
}
