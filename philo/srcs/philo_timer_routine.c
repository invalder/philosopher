/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timer_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:04:19 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/02 23:59:07 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

void	*ft_philo_timer_routine(t_philo *philo)
{
	while (philo->rule->is_alive && philo->is_alive)
	{
		ft_philo_starving(philo);
		usleep(1);
	}
	return (NULL);
}

int	ft_philo_starving(t_philo *philo)
{
	size_t			current_time;
	size_t			current_time2;

	current_time2 = ft_current_time(philo->rule);
	current_time = current_time2 / 1000;
	if (philo->last_eat > current_time)
		return (0);
	if ((current_time - philo->last_eat) <= \
		((size_t) philo->rule->time_to_die))
		return (0);
	else
	{
		philo->is_alive = 0;
		philo->rule->is_alive = 0;
		printf(RED"%ld ms, %d is dying\n"COLOR_RESET, \
			current_time, philo->philo_num);
		if (philo->fork_left)
			pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(&philo->fork_right);
		return (1);
	}
}
