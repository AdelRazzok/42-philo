/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:21:41 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 17:06:05 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error.\nInvalid number of argument.\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!is_str_numeric(argv[i]))
		{
			printf("Error.\nOnly numeric arguments are allowed.\n");
			return (0);
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Error.\nOnly positive values are allowed.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_malloc(char *msg, t_args *args, t_philo *philo, int is_alloc)
{
	if (is_alloc)
	{
		if (args->fork)
			free(args->fork);
		if (args->death)
			free(args->death);
		if (philo)
			free(philo);
	}
	printf("Error.\n%s\n", msg);
	return (1);
}
