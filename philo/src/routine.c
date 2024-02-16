/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:16:22 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/16 16:01:50 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	philo->last_time_ate = get_current_time();
	ft_usleep(philo->args->time_to_eat);
	print_action(philo, "is eating");
	philo->nb_time_ate++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	_sleep(t_philo *philo)
{
	ft_usleep(philo->args->time_to_sleep);
	print_action(philo, "is sleeping");
}

static void	_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!get_is_ready(philo->args))
		continue ;
	if (philo->id % 2 != 0)
		ft_usleep(philo->args->time_to_eat * 0.5);
	while (!philo->args->is_over)
	{
		_eat(philo);
		_sleep(philo);
		_think(philo);
	}
	return (NULL);
}
