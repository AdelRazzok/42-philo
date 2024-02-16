/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:53:35 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/16 16:31:28 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_is_ready(t_args *args)
{
	int	is_ready;

	is_ready = 0;
	pthread_mutex_lock(&args->is_ready_m);
	if (args->is_ready)
		is_ready = 1;
	pthread_mutex_unlock(&args->is_ready_m);
	return (is_ready);
}

void	set_is_ready(t_args *args, int value)
{
	pthread_mutex_lock(&args->is_ready_m);
	args->is_ready = value;
	pthread_mutex_unlock(&args->is_ready_m);
}

int	get_is_over(t_args *args)
{
	int	is_over;

	is_over = 0;
	pthread_mutex_lock(&args->is_over_m);
	if (args->is_over)
		is_over = 1;
	pthread_mutex_unlock(&args->is_over_m);
	return (is_over);
}

void	set_is_over(t_args *args, int value)
{
	pthread_mutex_lock(&args->is_over_m);
	args->is_over = value;
	pthread_mutex_unlock(&args->is_over_m);
}
