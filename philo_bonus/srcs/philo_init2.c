/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:14:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/28 01:48:54 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_philo_timer_create(t_meta *meta, t_rules *rules)
{
	(void) rules;
	if (pthread_create(&meta->philo_meta[0].philo_timer, NULL, \
			(void *)ft_philo_timer_routine, &meta->philo_meta[0]))
	{
		perror("Failed to create timer thread");
		return (1);
	}
	return (0);
}

int	ft_philo_timer_join(t_meta *meta, t_rules *rules)
{
	(void) rules;
	usleep(5000);
	if (pthread_join(meta->philo_meta[0].philo_timer, NULL))
	{
		perror("Failed to join timer thread");
		return (1);
	}
	return (0);
}
