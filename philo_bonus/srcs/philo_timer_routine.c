/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timer_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:04:19 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 01:25:55 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
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

	current_time = ft_current_time(philo->rule) / 1000;
	if ((current_time - philo->last_eat) <= \
		((size_t) philo->rule->time_to_die))
		return (0);
	else
	{
		philo->is_alive = 0;
		philo->rule->is_alive = 0;
		sem_wait(philo->rule->actionsem);
		printf(RED"%ld ms, %d is dying\n"COLOR_RESET, \
			current_time, philo->philo_num);
		if (philo->eat_allow == 1 || philo->eat_allow == 2)
		{
			sem_post(philo->rule->semaphore);
		}
		if (philo->eat_allow == 3)
		{
			sem_post(philo->rule->semaphore);
			sem_post(philo->rule->semaphore);
		}
		return (1);
	}
}
