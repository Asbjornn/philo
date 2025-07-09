/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:17:24 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 11:02:14 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_arguments	fill_arg( char *argv[], t_arguments *arg)
{
	arg->nb_philo = ft_atoi(argv[1]);
	printf("%d\n", arg->nb_philo);
	arg->time_die = ft_atoi(argv[2]);
	printf("%d\n", arg->time_die);
	arg->time_eat = ft_atoi(argv[3]);
	printf("%d\n", arg->time_eat);
	arg->time_sleep = ft_atoi(argv[4]);
	printf("%d\n", arg->time_sleep);
	if (argv[5])
		arg->eat_times = ft_atoi(argv[5]);
	else
		arg->eat_times = -1;
	return (*arg);
}

static void	*routine(void *data)
{
	pthread_t	thid;
	t_arguments	*arg;
	int			i;

	arg = (t_arguments *)data;
	thid = pthread_self();
	printf("Hi, im the thread [%p]\n", (void *)thid);
	printf("we are %d philos\n", arg->nb_philo);
	i = 0;
	while (i < 3)
	{
		state_eat(arg->time_eat);
		state_sleep(arg->time_sleep);
		state_think(arg->time_sleep + 1000);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo	phil;
	t_philo	arn;
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
			return (printf("dk,eqd"), 0);
		printf("dzlkd,qd\n");
		pthread_create(&phil.thread, NULL, routine, &arg);
		pthread_create(&arn.thread, NULL, routine, &arg);
	}
	pthread_join(phil.thread, NULL);
	pthread_join(arn.thread, NULL);
	return (0);
}
