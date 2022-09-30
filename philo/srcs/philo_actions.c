/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:12:34 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/01 02:16:16 by nnakarac         ###   ########.fr       */
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
		ft_myusleep(250);
		if (philo->rule->is_alive && philo->is_alive)
		{
			take_fork = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
			{
				printf(BBLU "%ld ms, %d has taken a fork\n" COLOR_RESET, \
					take_fork, philo->philo_num);
			}
			else
				return (1);
			philo->eat_allow += 1;
			return (0);
		}
	}
	return (1);
}

int	ft_philo_fork_right(t_philo *philo)
{
	size_t	take_fork;

	take_fork = 0;
	if (philo->rule->is_alive && philo->eat_allow == 1 && \
		(philo->eat_allow != 2 && philo->eat_allow != 3) && \
		!pthread_mutex_lock(&philo->fork_right))
	{
		ft_myusleep(250);
		if (philo->rule->is_alive && philo->is_alive)
		{
			take_fork = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
			{
				printf(BMAG"%ld ms, %d has taken a fork\n"COLOR_RESET, \
					take_fork, philo->philo_num);
			}
			else
				return (1);
			philo->eat_allow += 2;
			return (0);
		}
	}
	return (1);
}

int	ft_philo_eat(t_philo *philo)
{
	size_t	current_eat;

	current_eat = 0;
	if (philo->rule->is_alive && philo->is_alive && philo->eat_allow == 3)
	{
		ft_myusleep(1000);
		if (philo->rule->is_alive && philo->is_alive)
		{
			current_eat = ft_current_time(philo->rule) / 1000;
			printf(CYN"%ld ms, %d is eating\n"COLOR_RESET, \
				current_eat, philo->philo_num);
			philo->last_eat = current_eat;
			ft_myusleep(1000 * philo->rule->time_to_eat);
			if (philo->rule->is_alive && philo->fork_left)
				pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(&philo->fork_right);
			philo->eat_allow += 1;
			ft_philo_countdownt_philo(philo);
			return (0);
		}
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
		ft_myusleep(250);
		if (philo->rule->is_alive && philo->is_alive)
		{
			current_sleep = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
				printf(RED"%ld ms, %d is sleeping\n"COLOR_RESET, \
					current_sleep, philo->philo_num);
			else
				return (1);
			philo->last_sleep = current_sleep / 1000;
			ft_myusleep(1000 * philo->rule->time_to_sleep);
			philo->eat_allow += 1;
			return (0);
		}
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
		ft_myusleep(250);
		if (philo->rule->is_alive && philo->is_alive)
		{
			current_think = ft_current_time(philo->rule) / 1000;
			if (philo->rule->is_alive && philo->is_alive)
				printf(YEL"%ld ms, %d is thinking\n"COLOR_RESET, \
					current_think, philo->philo_num);
			else
				return (1);
			philo->eat_allow = 0;
			return (0);
		}
	}
	return (1);
}
