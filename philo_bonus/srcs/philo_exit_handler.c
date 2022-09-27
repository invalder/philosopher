/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:29:29 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/28 01:44:18 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_semaphore_destroy(t_rules *rules)
{
	(void) rules;
	// int	cnt;

	// cnt = 0;
	// while (cnt < rules->num_philo)
	// {
	// 	sem_unlink("/philo_sem");
	// }
	// free(rules->semaphore);
	sem_unlink("/philo_sem");
	return (0);
}

int	ft_kill_other_children(t_meta *meta, t_rules *rules)
{
	int	cnt;

	cnt = 0;
	while (cnt < rules->num_philo)
	{
		if (cnt != (meta->philo_id - 1))
		{
			if (kill(meta->proc_list[cnt], SIGKILL) < 0)
			{
				perror("Failed to kill");
				exit(1);
			}
			else
				printf("%d Killed\n", meta->proc_list[cnt]);
		}
		cnt++;
	}
	free(meta->proc_list);
	meta->proc_list = NULL;
	return (0);
}
