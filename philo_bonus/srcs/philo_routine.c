/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:03:52 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/28 00:00:56 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

void	*ft_philo_routine(t_philo *philo)
{
	// int	semval;

	// semval = 0;
	while (philo->rule->is_alive && philo->is_alive)
	{
		// printf("%d sem_wait = %d\n", philo->philo_num, sem_wait(philo->rule->semaphore));
		// sem_getvalue(philo->rule->semaphore, &semval);
		// printf("%d semval = %d\n", philo->philo_num, semval);

		// printf("%d sem_wait = %d\n", philo->philo_num, sem_wait(philo->rule->semaphore));
		// sem_getvalue(philo->rule->semaphore, &semval);
		// printf("%d semval = %d\n", philo->philo_num, semval);

		// printf("%d sem_post = %d\n", philo->philo_num, sem_post(philo->rule->semaphore));
		// sem_getvalue(philo->rule->semaphore, &semval);
		// printf("%d semval = %d\n", philo->philo_num, semval);

		// printf("%d sem_post = %d\n", philo->philo_num, sem_post(philo->rule->semaphore));
		// sem_getvalue(philo->rule->semaphore, &semval);
		// printf("%d semval = %d\n", philo->philo_num, semval);

		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_fork_left(philo);
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_fork_right(philo);
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_eat(philo);
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_sleep(philo);
		if (philo->rule->is_alive && philo->is_alive)
			ft_philo_think(philo);
	}
	return (NULL);
}
