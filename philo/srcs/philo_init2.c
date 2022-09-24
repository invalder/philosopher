/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:59:57 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/18 13:10:40 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

int	ft_philo_timer_create(t_meta *meta, t_rules *rules)
{
	int	num_philo;
	int	max_philo;

	num_philo = 0;
	max_philo = rules->num_philo;
	while (num_philo < max_philo)
	{
		if (pthread_create(&meta->philo_meta[num_philo].philo_timer, NULL, \
			(void *)ft_philo_timer_routine, &meta->philo_meta[num_philo]))
		{
			perror("Failed to create timer thread");
			return (1);
		}
		num_philo += 1;
	}
	return (0);
}

int	ft_philo_timer_join(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	usleep(5000);
	while (num_philo < rules->num_philo)
	{
		if (pthread_join(meta->philo_meta[num_philo].philo_timer, NULL))
		{
			perror("Failed to join timer thread");
			return (1);
		}
		num_philo += 1;
	}
	return (0);
}
