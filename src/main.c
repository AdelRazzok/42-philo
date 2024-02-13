/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 11:32:49 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_init_agrs(char **argv, t_args *args);

void	print_args(t_args *args)
{
	printf("nb_philos: %d\n", args->nb_philos);
	printf("time_to_die: %d\n", args->time_to_die);
	printf("time_to_eat: %d\n", args->time_to_eat);
	printf("time_to_sleep: %d\n", args->time_to_sleep);
	printf("nb_each_philo_eat: %d\n", args->nb_each_philo_eat);
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (!check_args(argc, argv))
		return (1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (1);
	_init_agrs(argv, args);
	print_args(args);
	free(args);
	return (0);
}

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
