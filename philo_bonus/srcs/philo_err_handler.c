/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_err_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:17 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/29 01:00:38 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_malloc_chk(void *ptr, t_meta *meta, t_rules *rules)
{
	if (ptr == NULL)
	{
		if (meta->philo_meta)
			free(meta->philo_meta);
		if (meta->proc_list)
			free(meta->proc_list);
		ft_semaphore_destroy(meta, rules);
		ft_kill_other_children(meta, rules);
		exit(1);
	}
	return (0);
}

int	ft_fork_chk(int id, t_meta *meta, t_rules *rules)
{
	if (id < 0)
	{
		perror("Failed to create process");
		if (meta->philo_meta)
			free(meta->philo_meta);
		if (meta->proc_list)
			free(meta->proc_list);
		ft_semaphore_destroy(meta, rules);
		ft_kill_other_children(meta, rules);
		exit(1);
	}
	return (0);
}
