/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:08:48 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 17:27:29 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		philo[i].id = i;
		philo[i].is_dead = 0;
		philo[i].nb_time_ate = 0;
		philo[i].thread_start = 0;
		philo[i].last_time_ate = get_current_time();
		philo[i].left_fork = &args->fork[i];
		philo[i].right_fork = 0;
		philo[i].args = args;
		i++;
	}
	return (0);
}
