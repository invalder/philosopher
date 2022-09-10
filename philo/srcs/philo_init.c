/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:36:53 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/10 18:10:53 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_create(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < rules->num_philo)
	{
		meta->philo_meta[num_philo].philo_num = num_philo;
		meta->philo_meta[num_philo].is_alive = 1;
		meta->philo_meta[num_philo].last_eat = 0;
		meta->philo_meta[num_philo].last_sleep = 0;
		meta->philo_meta[num_philo].last_think = 0;
		meta->philo_meta[num_philo].rule = rules;
		meta->philo_meta[num_philo].fork_left = \
			&meta->philo_meta[(num_philo + 1) % rules->num_philo].philo_fork;
		meta->philo_meta[num_philo].fork_right = \
			&meta->philo_meta[(num_philo - 1) % rules->num_philo].philo_fork;
		pthread_mutex_init(&meta->philo_meta[num_philo].philo_fork, NULL);
		if (pthread_create(&meta->philo_meta[num_philo].philosopher, NULL, \
			(void *)ft_philo_routine, &meta->philo_meta[num_philo]))
		{
			perror("Failed to create thread");
			return (1);
		}
		num_philo++;
	}
	return (0);
}

int	ft_philo_join(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < rules->num_philo)
	{
		if (pthread_join(meta->philo_meta[num_philo].philosopher, NULL))
		{
			perror("Failed to join thread");
			return (1);
		}
		num_philo++;
	}
	return (0);
}

int	ft_philo_init(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	meta->philo_meta = malloc(sizeof(t_philo) * rules->num_philo);
	if (!meta->philo_meta)
		return (1);
	if (ft_philo_create(meta, rules))
		return (1);
	if (ft_philo_join(meta, rules))
		return (1);
	return (0);
}
