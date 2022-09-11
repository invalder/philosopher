/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:08:26 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/11 12:31:47 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eating(t_philo *philo)
{
	struct timeval	tv;
	size_t			current_eat;

	if (philo->eat_allow >= 3)
	{
		gettimeofday(&tv, NULL);
		current_eat = tv.tv_sec * 1000000 + tv.tv_usec;
		if (current_eat - philo->last_eat +)
	}
	return (0);
}

int	ft_philo_sleeping(t_philo *philo)
{
	struct timeval	tv;


	return (0);
}
