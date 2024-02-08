/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:21:41 by arazzok           #+#    #+#             */
/*   Updated: 2024/02/08 18:32:55 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int static	_is_str_numeric(char *str);

int	check_args(int argc, char **argv)
{
    int i;

	if (argc < 5 || argc > 6)
	{
		printf("Error.\nInvalid number of argument.\n");
		return (0);
	}
    i = 0;
    while (argv[i])
    {
        if (!_is_str_numeric(argv[i]))
        {
            printf("Error.\nOnly numeric arguments alowed.\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int static	_is_str_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
