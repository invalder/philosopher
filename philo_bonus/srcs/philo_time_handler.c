/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:38:08 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/24 14:03:52 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

//current time return time diff from initial in us
size_t	ft_current_time(t_rules *rules)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000 + tv.tv_usec) - rules->time_init);
}

size_t	ft_current_time_rel(size_t current_time, t_rules *rules)
{
	return (current_time - rules->time_init);
}

size_t	ft_conv_us_ms(size_t current_time)
{
	return (current_time / 1000);
}

void	ft_myusleep(size_t	time)
{
	struct timeval	tv;
	size_t			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000000) + tv.tv_usec;
	usleep(time * 0.95);
	while ((((tv.tv_sec * 1000000) + tv.tv_usec) - current_time) <= time)
	{
		gettimeofday(&tv, NULL);
		usleep(1);
	}
}
