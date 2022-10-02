/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:07:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 01:26:06 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_philo_meta_init(t_meta *meta, t_rules *rules)
{
	meta->philo_meta[0].philo_num = meta->philo_id;
	meta->philo_meta[0].is_alive = 1;
	meta->philo_meta[0].eat_allow = 0;
	meta->philo_meta[0].last_eat = 0;
	meta->philo_meta[0].last_sleep = 0;
	meta->philo_meta[0].rule = rules;
	if (rules->num_eat_time > 0)
		meta->philo_meta[0].time_to_eat = rules->num_eat_time;
	return (0);
}

int	ft_philo_time_init(t_meta *meta, t_rules *rules)
{
	(void) rules;
	meta->philo_meta[0].last_eat = 0;
	meta->philo_meta[0].last_sleep = 0;
	return (0);
}

int	ft_philo_create(t_meta *meta, t_rules *rules)
{
	(void) rules;
	if (meta->philo_id % 2 == 0)
		usleep(500);
	if (pthread_create(&meta->philo_meta[0].philosopher, NULL, \
		(void *)ft_philo_routine, &meta->philo_meta[0]))
	{
		perror("Failed to create thread");
		return (1);
	}
	return (0);
}

int	ft_philo_join(t_meta *meta, t_rules *rules)
{
	(void) rules;
	if (pthread_join(meta->philo_meta[0].philosopher, NULL))
	{
		perror("Failed to join thread");
		return (1);
	}
	return (0);
}

int	ft_philo_init(t_meta *meta, t_rules *rules)
{
	struct timeval	tv;

	meta->proc_list = malloc(sizeof(int) * rules->num_philo);
	ft_malloc_chk(meta->proc_list, meta, rules);
	memset(meta->proc_list, 0, sizeof(int) * rules->num_philo);
	ft_philo_first_fork(1, meta, rules);
	if (!meta->proc_id)
	{
		meta->philo_meta = malloc(sizeof(t_philo) * 1);
		ft_malloc_chk(meta->philo_meta, meta, rules);
		memset(meta->philo_meta, 0, sizeof(t_philo) * 1);
		gettimeofday(&tv, NULL);
		rules->time_init = (tv.tv_sec * 1000000) + tv.tv_usec;
		if (ft_philo_time_init(meta, rules))
			return (1);
		ft_philo_meta_init(meta, rules);
		if (ft_philo_create(meta, rules) || ft_philo_timer_create(meta, rules))
			return (1);
		if (ft_philo_join(meta, rules))
			return (1);
	}
	else
		sleep(1);
	return (0);
}
