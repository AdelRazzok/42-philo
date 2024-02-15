/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:08:48 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/15 19:21:27 by arazzok          ###   ########.fr       */
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
		philo[i].last_time_ate = 0;
		philo[i].left_fork = &args->fork[i];
		philo[i].right_fork = 0;
		philo[i].args = args;
		i++;
	}
	return (0);
}

int	is_someone_dead(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->args->death);
	time = get_current_time() - philo->last_time_ate;
	if (time >= (size_t)philo->args->time_to_die)
	{
		pthread_mutex_unlock(philo->args->death);
		print_action(philo, "died");
		philo->args->is_over = 1;
		philo->is_dead = 1;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->args->death);
	return (0);
}

int	is_someone_full(t_philo *philo, int current)
{
	if (philo->args->is_nb_meals
		&& current == philo->args->nb_philos - 1
		&& philo->nb_time_ate == philo->args->nb_meals)
		return (ft_usleep(300));
	return (0);
}
