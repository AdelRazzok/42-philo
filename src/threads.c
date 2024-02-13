/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:53:00 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/13 12:15:33 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *thread_routine(void *data)
{
    pthread_t   thread;

    (void)data;
    thread = pthread_self();
    printf("Thread [%ld] is running\n", thread);
    return (NULL);
}
