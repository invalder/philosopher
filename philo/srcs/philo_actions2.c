/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:35:40 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/01 01:31:10 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

int	ft_philo_countdownt_philo(t_philo *philo)
{
	if (philo->rule->num_eat_time > 0)
	{
		philo->time_to_eat--;
		if (!philo->time_to_eat)
			philo->is_alive = 0;
		return (0);
	}
	return (1);
}
