/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:03:52 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 00:12:13 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

void	*ft_philo_routine(t_philo *philo)
{
	while (philo->rule->is_alive && philo->is_alive)
	{
		if (philo->rule->is_alive && philo->is_alive)
		{
			pthread_mutex_lock(&philo->time_key);
			ft_philo_fork_left(philo);
			pthread_mutex_unlock(&philo->time_key);
		}
		if (philo->rule->is_alive && philo->is_alive)
		{
			pthread_mutex_lock(&philo->time_key);
			ft_philo_fork_right(philo);
			pthread_mutex_unlock(&philo->time_key);
		}
		if (philo->rule->is_alive && philo->is_alive)
		{
			pthread_mutex_lock(&philo->time_key);
			ft_philo_eat(philo);
			pthread_mutex_unlock(&philo->time_key);
		}
		ft_philo_routine2(philo);
	}
	return (NULL);
}

void	*ft_philo_routine2(t_philo *philo)
{
	if (philo->rule->is_alive && philo->is_alive)
	{
		pthread_mutex_lock(&philo->time_key);
		ft_philo_sleep(philo);
		pthread_mutex_unlock(&philo->time_key);
	}
	if (philo->rule->is_alive && philo->is_alive)
	{
		pthread_mutex_lock(&philo->time_key);
		ft_philo_think(philo);
		pthread_mutex_unlock(&philo->time_key);
	}
	return (NULL);
}
