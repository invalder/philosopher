/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:12:34 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/18 15:09:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

int	ft_philo_fork_left(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	if (philo->rule->is_alive && \
		(philo->eat_allow != 1 && philo->eat_allow != 3) && \
		philo->fork_left && !pthread_mutex_lock(philo->fork_left))
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

int	ft_philo_fork_right(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	if (philo->rule->is_alive && \
		(philo->eat_allow != 2 && philo->eat_allow != 3) && \
		!pthread_mutex_lock(&philo->fork_right))
	{
		take_fork = ft_current_time(philo->rule) / 1000;
		printf(BMAG"%ld ms, %d has taken a fork\n"COLOR_RESET, \
			take_fork, \
			philo->philo_num);
		philo->eat_allow += 2;
		return (0);
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
		if (philo->rule->is_alive && philo->fork_left)
			pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(&philo->fork_right);
		philo->eat_allow += 1;
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
		current_sleep = ft_current_time(philo->rule) / 1000;
		printf(RED"%ld ms, %d is sleeping\n"COLOR_RESET, \
			current_sleep, \
			philo->philo_num);
		philo->last_sleep = current_sleep / 1000;
		ft_myusleep(1000 * philo->rule->time_to_sleep);
		philo->eat_allow += 1;
		return (0);
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
		current_think = ft_current_time(philo->rule) / 1000;
		printf(YEL);
		printf("%ld ms, %d is thinking\n", \
			current_think, \
			philo->philo_num);
		printf(COLOR_RESET);
		if (philo->rule->num_eat_time == -1)
			philo->eat_allow = 0;
		return (0);
	}
	return (1);
}
