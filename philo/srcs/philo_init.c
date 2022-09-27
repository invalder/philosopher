/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:36:53 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/28 02:22:20 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

int	ft_philo_meta_init(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < rules->num_philo)
	{
		meta->philo_meta[num_philo].philo_num = num_philo + 1;
		meta->philo_meta[num_philo].is_alive = 1;
		meta->philo_meta[num_philo].eat_allow = 0;
		meta->philo_meta[num_philo].last_eat = 0;
		meta->philo_meta[num_philo].last_sleep = 0;
		meta->philo_meta[num_philo].fork_left = NULL;
		meta->philo_meta[num_philo].rule = rules;
		meta->philo_meta[num_philo].fork_right = \
			(pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
		if (rules->num_eat_time > 0)
			meta->philo_meta[num_philo].time_to_eat = rules->num_eat_time;
		num_philo++;
	}
	return (0);
}

int	ft_philo_time_init(t_meta *meta, t_rules *rules)
{
	int	num_philo;

	num_philo = 0;
	while (num_philo < rules->num_philo)
	{
		meta->philo_meta[num_philo].last_eat = 0;
		meta->philo_meta[num_philo].last_sleep = 0;
		num_philo++;
	}
	return (0);
}

int	ft_philo_create(t_meta *meta, t_rules *rules)
{
	int	num_philo;
	int	max_philo;

	num_philo = 0;
	max_philo = rules->num_philo;
	while (num_philo < max_philo)
	{
		if (max_philo > 1)
			meta->philo_meta[num_philo].fork_left = \
				&meta->philo_meta[(num_philo + 1) % max_philo].fork_right;
		pthread_mutex_init(&meta->philo_meta[num_philo].fork_right, NULL);
		if (pthread_create(&meta->philo_meta[num_philo].philosopher, NULL, \
			(void *)ft_philo_routine, &meta->philo_meta[num_philo]))
		{
			perror("Failed to create thread");
			return (1);
		}
		num_philo += 2;
		if (num_philo >= rules->num_philo && !(num_philo % 2))
		{
			usleep(500);
			num_philo = 1;
		}
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
		num_philo += 2;
		if (num_philo >= rules->num_philo && !(num_philo % 2))
		{
			usleep(500);
			num_philo = 1;
		}
	}
	return (0);
}

int	ft_philo_init(t_meta *meta, t_rules *rules)
{
	struct timeval	tv;

	meta->philo_meta = malloc(sizeof(t_philo) * rules->num_philo);
	if (!meta->philo_meta)
		return (1);
	ft_philo_meta_init(meta, rules);
	if (ft_philo_create(meta, rules))
		return (1);
	if (ft_philo_timer_create(meta, rules))
		return (1);
	gettimeofday(&tv, NULL);
	rules->time_init = tv.tv_sec * 1000000 + tv.tv_usec;
	if (ft_philo_time_init(meta, rules))
		return (1);
	if (ft_philo_join(meta, rules))
		return (1);
	if (ft_philo_timer_join(meta, rules))
		return (1);
	return (0);
}
