/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/16 17:00:59 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_init_mutex(t_args *args)
{
	int	i;

	i = 0;
	args->fork = NULL;
	args->fork = malloc(sizeof(pthread_mutex_t) * args->nb_philos);
	if (!args->fork)
		return (check_malloc("Fork malloc failed.", args, NULL, 1));
	while (i < args->nb_philos)
	{
		if (pthread_mutex_init(&args->fork[i], NULL) == -1)
			return (check_malloc("Fork mutex init failed.", args, NULL, 1));
		i++;
	}
	pthread_mutex_init(&args->death, NULL);
	pthread_mutex_init(&args->is_ready_m, NULL);
	pthread_mutex_init(&args->is_over_m, NULL);
	return (0);
}

static int	_init_args(char **argv, t_args *args)
{
	args->nb_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		args->nb_meals = ft_atoi(argv[5]);
		args->is_nb_meals = 1;
	}
	else
	{
		args->nb_meals = -1;
		args->is_nb_meals = 0;
	}
	args->is_over = 0;
	args->is_ready = 0;
	args->start_time = 0;
	return (_init_mutex(args));
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (!check_args(argc, argv))
		return (1);
	if (_init_args(argv, &args))
		return (1);
	if (process_threads(&args))
		return (1);
	return (0);
}
