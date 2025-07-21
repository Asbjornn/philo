/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:17:24 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/21 20:59:09 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

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
	t_table	table;

	if (argc < 5 || argc > 6)
		return (write_error(FORMAT));
	else
	{
		if (parse_arg(argv) == 1)
			return (write_error(ARGUMENT));
		table.arg = fill_arg(argv, &table.arg);
		if (table.arg.nb_philo <= 0 || table.arg.time_die <= 0)
			return (write_error(VALUE));
		init_table(&table);
		start_dinner(&table);
		end_dinner(&table);
	}
	return (0);
}
