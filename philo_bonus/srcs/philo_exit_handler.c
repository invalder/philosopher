/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:29:29 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 01:19:42 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_semaphore_destroy(t_rules *rules)
{
	int	cnt;

	cnt = 0;
	while (cnt < rules->num_philo)
	{
		if (sem_destroy(&rules->semaphore[cnt++]))
			exit(1);
	}
	free(rules->semaphore);
	return (0);
}

int	ft_kill_other_children(t_meta *meta, t_rules *rules)
{
	int	cnt;

	cnt = 0;
	while (cnt < rules->num_philo)
	{
		if (meta->proc_list[cnt] != meta->proc_id)
		{
			if (kill(meta->proc_list[cnt], SIGKILL) < 0)
			{
				perror("Failed to kill");
				exit(1);
			}
		}
	}
	return (0);
}
