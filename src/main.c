/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:52 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/08 18:41:41 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_init_agrs(char **argv, t_args *args);

int	main(int argc, char **argv)
{
	t_args	*args;

	if (!check_args(argc, argv))
		return (1);
	args = (t_args *) malloc(sizeof(t_args));
	if (!args)
		return (1);
	_init_agrs(argv, args);
	free(args);
	return (0);
}

static int	_init_agrs(char **argv, t_args *args)
{
	return (0);
}
