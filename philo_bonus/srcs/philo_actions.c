/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:12:34 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/28 03:11:18 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_philo_fork_left(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	if (philo->rule->is_alive && \
		(philo->eat_allow != 1 && philo->eat_allow != 3) && \
		!sem_wait(philo->rule->semaphore))
	{
		if (philo->rule->is_alive && philo->is_alive)
		{
			take_fork = ft_current_time(philo->rule) / 1000;
			printf(BBLU "%ld ms, %d has taken a fork\n" COLOR_RESET, \
				take_fork, \
				philo->philo_num);
			philo->eat_allow += 1;
			return (0);
		}
		return (1);
	}
	return (1);
}

int	ft_philo_fork_right(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	if (philo->rule->is_alive && \
		(philo->eat_allow != 2 && philo->eat_allow != 3) && \
		!sem_wait(philo->rule->semaphore))
	{
		if (philo->rule->is_alive && philo->is_alive)
		{
			take_fork = ft_current_time(philo->rule) / 1000;
			printf(BBLU "%ld ms, %d has taken a fork\n" COLOR_RESET, \
				take_fork, \
				philo->philo_num);
			philo->eat_allow += 2;
			return (0);
		}
		return (1);
	}
	return (1);
}

int	ft_philo_eat(t_philo *philo)
{
	size_t	current_eat;

	current_eat = 0;
	if (philo->rule->is_alive && philo->is_alive && \
		philo->eat_allow == 3)
	{
		current_eat = ft_current_time(philo->rule) / 1000;
		printf(CYN"%ld ms, %d is eating\n"COLOR_RESET, \
			current_eat, \
			philo->philo_num);
		philo->last_eat = current_eat;
		ft_myusleep(1000 * philo->rule->time_to_eat);
		sem_post(philo->rule->semaphore);
		sem_post(philo->rule->semaphore);
		philo->eat_allow += 1;
		if (philo->rule->num_eat_time > 0)
		{
			philo->time_to_eat--;
			if (!philo->time_to_eat)
				philo->is_alive = 0;
		}
		return (0);
	}
	return (1);
}

int	ft_philo_sleep(t_philo *philo)
{
	size_t	current_sleep;

	current_sleep = 0;
	if (philo->rule->is_alive && philo->is_alive \
		&& philo->eat_allow == 4)
	{
		if (philo->rule->is_alive && philo->is_alive)
		{
			current_sleep = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
			{
				printf(RED"%ld ms, %d is sleeping\n"COLOR_RESET, \
					current_sleep, \
					philo->philo_num);
			}
			philo->last_sleep = current_sleep / 1000;
			ft_myusleep(1000 * philo->rule->time_to_sleep);
			philo->eat_allow += 1;
			return (0);
		}
		return (1);
	}
	return (1);
}

int	ft_philo_think(t_philo *philo)
{
	size_t	current_think;

	current_think = 0;
	if (philo->rule->is_alive && philo->is_alive \
		&& philo->eat_allow == 5)
	{
		if (philo->rule->is_alive && philo->is_alive)
		{
			current_think = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
			{
				printf(YEL"%ld ms, %d is thinking\n"COLOR_RESET, \
					current_think, \
					philo->philo_num);
			}
			philo->eat_allow = 0;
			return (0);
		}
	}
	return (1);
}
