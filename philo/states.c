/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:22:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/07/09 09:52:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    state_eat(int time)
{
    printf("I'm in eat state and i wait [%d] milliseconds\n", time);
    usleep(time);
}

void    state_sleep(int time)
{
    printf("I'm in sleep state and i wait [%d] milliseconds\n", time);
    usleep(time);
}

void    state_think(int time)
{
    printf("I'm in think state and i wait [%d] milliseconds\n", time);
    usleep(time);   
}
