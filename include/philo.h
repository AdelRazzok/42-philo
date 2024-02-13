/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:30:24 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 11:32:56 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_args
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_each_philo_eat;
}		t_args;

/* ###@ ERROR */
int		check_args(int argc, char **argv);

/* ###@ UTILS */
int		ft_atoi(const char *str);

#endif
