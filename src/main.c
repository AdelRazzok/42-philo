/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 12:14:13 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_init_agrs(char **argv, t_args *args)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (i == 1)
			args->nb_philos = ft_atoi(argv[i]);
		else if (i == 2)
			args->time_to_die = ft_atoi(argv[i]);
		else if (i == 3)
			args->time_to_eat = ft_atoi(argv[i]);
		else if (i == 4)
			args->time_to_sleep = ft_atoi(argv[i]);
		else if (i == 5)
			args->nb_each_philo_eat = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}

static void	_process_threads(t_args *args, pthread_t *thread1,
		pthread_t *thread2)
{
	(void)args;
	pthread_create(thread1, NULL, &thread_routine, NULL);
	pthread_create(thread2, NULL, &thread_routine, NULL);
	pthread_join(*thread1, NULL);
	pthread_join(*thread2, NULL);
}

int	main(int argc, char **argv)
{
	t_args		*args;
	pthread_t	thread1;
	pthread_t	thread2;

	if (!check_args(argc, argv))
		return (1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (1);
	_init_agrs(argv, args);
	_process_threads(args, &thread1, &thread2);
	free(args);
	return (0);
}
