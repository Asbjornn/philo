/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:05:51 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/15 09:45:19 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void    start_dinner(t_table *table)
{
    int i;

    i = 0;
    while (i < table->arg.nb_philo)
    {
        pthread_create(&table->philos[i].thread, NULL, routine, table);
        i++;
    }
}

void    end_dinner(t_table *table)
{
    int i;

    i = 0;
    while (i < table ->arg.nb_philo)
    {
        pthread_join(table->philos[i].thread, NULL);
        pthread_mutex_destroy(&table->forks[i].fork);
        free(&table->forks[i]);
        free(&table->philos[i]);
        i++;
    }
    free(table);
}