/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:52:47 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/15 01:40:25 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(t_philo *philo)
{
	while (philo->rule->is_alive && philo->is_alive)
	{
		if (philo->fork_left && !pthread_mutex_lock(philo->fork_left))
		{
			printf("%ld ms, %d has taken a fork\n", \
				ft_conv_us_ms(ft_current_time(philo->rule)), philo->philo_num);
			philo->eat_allow += 1;
		}
		if (!pthread_mutex_lock(&philo->fork_right))
		{
			printf("%ld ms, %d has taken a fork\n", \
				ft_conv_us_ms(ft_current_time(philo->rule)), philo->philo_num);
			philo->eat_allow += 2;
		}
		ft_philo_eating(philo);
		usleep(1000 * philo->rule->time_to_eat);
		if (philo->fork_left)
			pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(&philo->fork_right);
		philo->eat_allow = 0;
		if (philo->is_alive)
			ft_philo_sleeping(philo);
		usleep(1000 * philo->rule->time_to_sleep);
		if (philo->is_alive)
			printf("%ld ms, %d is thinking\n", \
				ft_conv_us_ms(ft_current_time(philo->rule)), philo->philo_num);
	}
	return (NULL);
}
