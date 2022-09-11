/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:52:47 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/11 11:45:27 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(t_philo *philo)
{
	while (philo->is_alive)
	{
		if (!pthread_mutex_lock(philo->fork_left))
		{
			printf("philo %d take fork left\n", philo->philo_num);
			philo->eat_allow += 1;
		}
		if (!pthread_mutex_lock(&philo->fork_right))
		{
			printf("philo %d take fork right\n", philo->philo_num);
			philo->eat_allow += 2;
		}
		usleep(1000 * philo->rule->time_to_eat);
		if (philo->eat_allow >= 3)
		{
			printf("philo %d is eating\n", philo->philo_num);
		}
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(&philo->fork_right);
		philo->eat_allow = 0;
		printf("philo %d is sleeping\n", philo->philo_num);
		usleep(1000 * philo->rule->time_to_sleep);
		printf("philo %d is thinking\n", philo->philo_num);
	}
	return (NULL);
}
