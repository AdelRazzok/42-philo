/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:53:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/16 17:49:59 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_init_threads(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		philo[i].right_fork = philo[(i + 1) % args->nb_philos].left_fork;
		if (pthread_create(&philo[i].thread,
				NULL, &philo_routine, &philo[i]) == -1)
			return (check_malloc("Thread creation failed.", args, philo, 1));
		i++;
	}
	args->start_time = get_current_time();
	i = 0;
	while (i < args->nb_philos)
	{
		philo[i].thread_start = args->start_time;
		philo[i].last_time_ate = args->start_time;
		i++;
	}
	set_is_ready(args, 1);
	return (0);
}

static int	_control_threads(t_args *args, t_philo *philo)
{
	int	i;

	while (!get_is_ready(args))
		continue ;
	while (!get_is_over(args))
	{
		i = 0;
		while (i < args->nb_philos)
		{
			if (is_someone_dead(&philo[i]) || is_someone_full(&philo[i], i))
				set_is_over(args, 1);
			i++;
		}
	}
	pthread_mutex_lock(&philo[args->nb_philos - 1].has_ate_m);
	if (args->is_nb_meals
		&& philo[args->nb_philos - 1].nb_time_ate == args->nb_meals)
	{
		pthread_mutex_unlock(&philo[args->nb_philos - 1].has_ate_m);
		ft_usleep(args->nb_philos * 5);
		printf("\nAll philos ate %d times\n", args->nb_meals);
		return (printf("\nNO ONE DIED! ;D\n"));
	}
	pthread_mutex_unlock(&philo[args->nb_philos - 1].has_ate_m);
	return (printf("\nSOMEONE DIED! :(\n"));
}

static void	_kill_threads(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->nb_philos)
	{
		pthread_join(philo[i].thread, (void *)&philo[i]);
		pthread_mutex_destroy(&philo[i].is_eating_m);
		pthread_mutex_destroy(&philo[i].has_ate_m);
		i++;
	}
	pthread_mutex_destroy(args->fork);
	pthread_mutex_destroy(&args->death);
	pthread_mutex_destroy(&args->is_ready_m);
	pthread_mutex_destroy(&args->is_over_m);
	free(args->fork);
	free(philo);
}

int	process_threads(t_args *args)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * args->nb_philos);
	if (!philo || init_philos(args, philo))
		return (1);
	if (_init_threads(args, philo))
		return (1);
	_control_threads(args, philo);
	_kill_threads(args, philo);
	return (0);
}
