/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:30:24 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 17:10:52 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				is_nb_meals;
	int				is_over;
	size_t			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*death;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				nb_time_ate;
	size_t			thread_start;
	size_t			last_time_ate;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_args			*args;
}					t_philo;

/* ###@ ERROR */
int					check_args(int argc, char **argv);
int					check_malloc(char *msg, t_args *args, t_philo *philo,
						int is_alloc);

/* ###@ UTILS */
int					ft_atoi(const char *str);
int					is_str_numeric(char *str);

/* ###@ THREADS */
int					process_threads(t_args *args);

/* ###@ PHILOS */
int					init_philos(t_args *args, t_philo *philo);

#endif
