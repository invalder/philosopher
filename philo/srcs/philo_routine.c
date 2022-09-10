/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:52:47 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/10 18:13:15 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(t_philo *philo)
{
	(void) philo;
	// printf("execution\n");
	// ft_print_rules(philo->rule);
	while (philo->is_alive)
	{
		if (!pthread_mutex_lock(philo->fork_left))
			printf("philo %d take fork left\n", philo->philo_num);
		if (!pthread_mutex_lock(philo->fork_right))
			printf("philo %d take fork right\n", philo->philo_num);
		usleep(1000 * philo->rule->time_to_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		usleep(1000 * philo->rule->time_to_sleep);
	}
	return (NULL);
}
