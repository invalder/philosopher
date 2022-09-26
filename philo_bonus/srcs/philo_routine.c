/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:03:52 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 01:24:50 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

void	*ft_philo_routine(t_philo *philo)
{
	(void) philo;
	while (philo->rule->is_alive && philo->is_alive)
	{
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_fork_left(philo);
		// if (philo->rule->is_alive && philo->is_alive)
		// 	ft_philo_fork_right(philo);
	// 	if (philo->rule->is_alive && philo->is_alive)
	// 		ft_philo_eat(philo);
	// 	if (philo->rule->is_alive && philo->is_alive)
	// 		ft_philo_countdownt_philo(philo);
	// 	if (philo->rule->is_alive && philo->is_alive)
	// 		ft_philo_sleep(philo);
	// 	if (philo->rule->is_alive && philo->is_alive)
	// 		ft_philo_think(philo);
	}
	return (NULL);
}
