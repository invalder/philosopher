/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:12:34 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 01:49:08 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_philo_fork_left(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	printf("taking fork \n");
	if (philo->rule->is_alive && \
		(philo->eat_allow != 1 && philo->eat_allow != 3) && \
		!sem_wait((philo->rule->semaphore)))
	{
		printf("took fork\n");
		take_fork = ft_current_time(philo->rule) / 1000;
		printf(BBLU "%ld ms, %d has taken a fork\n" COLOR_RESET, \
			take_fork, \
			philo->philo_num);
		philo->eat_allow += 1;
		return (0);
	}
	return (1);
}
