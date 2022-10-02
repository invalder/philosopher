/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:03:52 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 01:28:05 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

void	*ft_philo_release(t_philo *philo)
{
	if (philo->eat_allow == 1 || philo->eat_allow == 2)
		sem_post(philo->rule->semaphore);
	else if (philo->eat_allow == 3)
	{
		sem_post(philo->rule->semaphore);
		sem_post(philo->rule->semaphore);
	}
	return (NULL);
}

void	*ft_philo_routine(t_philo *philo)
{
	while (philo->rule->is_alive && philo->is_alive)
	{
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_fork_left(philo);
		else
			return (ft_philo_release(philo));
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_fork_right(philo);
		else
			return (ft_philo_release(philo));
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_eat(philo);
		else
			return (ft_philo_release(philo));
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_sleep(philo);
		else
			return (ft_philo_release(philo));
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_think(philo);
		else
			return (ft_philo_release(philo));
	}
	return (NULL);
}
