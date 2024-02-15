/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:53:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 17:29:26 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	process_threads(t_args *args)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * args->nb_philos);
	if (!philo)
		return (check_malloc("Philo malloc failed.", args, NULL, 1));
	init_philos(args, philo);
	// TODO: Init threads
	// TODO: Control threads
	// TODO: Join / Destroy threads
}
