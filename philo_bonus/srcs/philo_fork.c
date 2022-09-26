/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:12:16 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 01:16:18 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_philo_first_fork(int proccnt, t_meta *meta, t_rules *rules)
{
	meta->proc_id = fork();
	ft_fork_chk(meta->proc_id, meta, rules);
	if (meta->proc_id == 0)
	{
		meta->philo_id = proccnt;
		meta->proc_list[proccnt - 1] = getpid();
	}
	ft_philo_other_fork(proccnt, meta, rules);
	return (0);
}

int	ft_philo_other_fork(int proccnt, t_meta *meta, t_rules *rules)
{
	if (meta->proc_id != 0)
	{
		while (proccnt < rules->num_philo)
		{
			if (!meta->proc_id)
				break ;
			else
				meta->proc_id = fork();
			if (!meta->proc_id)
			{
				meta->philo_id = proccnt + 1;
				meta->proc_list[proccnt] = getpid();
			}
			else
				meta->philo_id = -1;
			proccnt++;
		}
	}
	return (0);
}
