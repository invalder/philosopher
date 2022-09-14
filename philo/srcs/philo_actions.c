/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:08:26 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/15 01:40:51 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_eating(t_philo *philo)
{
	size_t			current_eat;

	if (philo->eat_allow >= 3)
	{
		current_eat = ft_current_time(philo->rule);
		if ((current_eat - philo->last_eat) <= \
			(size_t) philo->rule->time_to_die * 1000)
		{
			printf("%ld ms, philo %d is eating\n", \
				ft_conv_us_ms(current_eat), philo->philo_num);
			philo->last_eat = current_eat;
		}
		else
		{
			printf("philo %d is dying from eating\n", philo->philo_num);
			philo->is_alive = 0;
			philo->rule->is_alive = 0;
		}
		return (0);
	}
	else
		return (ft_philo_starving(philo));
}

int	ft_philo_sleeping(t_philo *philo)
{
	size_t			current_sleep;

	current_sleep = ft_current_time(philo->rule);
	if ((current_sleep - philo->last_sleep) <= \
		(size_t) philo->rule->time_to_die * 1000)
	{
		printf("%ld ms, %d is sleeping\n", \
			ft_conv_us_ms(current_sleep), philo->philo_num);
		philo->last_sleep = current_sleep;
	}
	else
	{
		printf("philo %d is dying from sleeping\n", philo->philo_num);
		philo->is_alive = 0;
		philo->rule->is_alive = 0;
	}

	return (0);
}

int	ft_philo_starving(t_philo *philo)
{
	size_t			current_time;

	current_time = ft_current_time(philo->rule);
	if ((current_time - philo->last_eat)<= \
		(size_t) philo->rule->time_to_die * 1000)
		return (0);
	else
	{
		printf("philo %d is dying from starving\n", philo->philo_num);
		philo->is_alive = 0;
		philo->rule->is_alive = 0;
		return (1);
	}
}
