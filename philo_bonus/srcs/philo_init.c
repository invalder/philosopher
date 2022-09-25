/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:07:35 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/25 14:13:34 by nnakarac         ###   ########.fr       */
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
	if (pthread_create(&meta->philo_meta[0].philosopher, NULL, \
		(void *)ft_philo_routine, &meta->philo_meta[0]))
	{
		perror("Failed to create thread");
		return (1);
	}
	return (0);
}

int	ft_philo_init(t_meta *meta, t_rules *rules)
{
	struct timeval	tv;
	int				proccnt;

	(void) tv;
	(void) rules;
	proccnt = 1;
	meta->proc_id = fork();
	while (proccnt < rules->num_philo)
	{
		if (meta->proc_id != 0)
			meta->proc_id = fork();
		if (!meta->proc_id)
			meta->philo_id = proccnt - 1;
		else
			meta->philo_id = -1;
		proccnt++;
	}
	if (meta->proc_id != 0)
		sleep(1);
	// if (meta->proc_id == 0)
	printf("Hello form philo id %d",meta->philo_id);
	printf("Hello form %d my parents is %d\n", getpid(), getppid());
	if (!meta->proc_id)
	{
		meta->philo_meta = malloc(sizeof(t_philo) * 1);
		if (!meta->philo_meta)
			return (1);
		ft_philo_meta_init(meta, rules);
		if (ft_philo_create(meta, rules))
			return (1);
		if (ft_philo_timer_create(meta, rules))
			return (1);
		gettimeofday(&tv, NULL);
		rules->time_init = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	// if (!meta->philo_meta)
	// 	return (1);
	// ft_philo_meta_init(meta, rules);
	// if (ft_philo_create(meta, rules))
	// 	return (1);
	// if (ft_philo_timer_create(meta, rules))
	// 	return (1);
	// gettimeofday(&tv, NULL);
	// rules->time_init = tv.tv_sec * 1000000 + tv.tv_usec;
	// if (ft_philo_time_init(meta, rules))
	// 	return (1);
	// if (ft_philo_join(meta, rules))
	// 	return (1);
	// if (ft_philo_timer_join(meta, rules))
	// 	return (1);
	return (0);
}
