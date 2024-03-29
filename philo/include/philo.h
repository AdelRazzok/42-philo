/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:30:24 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/16 17:35:50 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				is_nb_meals;
	int				is_over;
	int				is_ready;
	size_t			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	death;
	pthread_mutex_t	is_ready_m;
	pthread_mutex_t	is_over_m;
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
	pthread_mutex_t	is_eating_m;
	pthread_mutex_t	has_ate_m;
	t_args			*args;
}					t_philo;

/* ###@ ERROR */
int					check_args(int argc, char **argv);
int					check_malloc(char *msg, t_args *args, t_philo *philo,
						int is_alloc);

/* ###@ UTILS */
int					ft_atoi(const char *str);
int					is_str_numeric(char *str);
size_t				get_current_time(void);
int					ft_usleep(size_t time);
void				print_action(t_philo *philo, char *action);

/* ###@ MUTEX */
int					get_is_ready(t_args *args);
void				set_is_ready(t_args *args, int value);
int					get_is_over(t_args *args);
void				set_is_over(t_args *args, int value);

/* ###@ THREADS */
int					process_threads(t_args *args);

/* ###@ PHILOS */
int					init_philos(t_args *args, t_philo *philo);
void				*philo_routine(void *ptr);
int					is_someone_dead(t_philo *philo);
int					is_someone_full(t_philo *philo, int current);

/* ###@ ROUTINE */
void				*philo_routine(void *ptr);

#endif
