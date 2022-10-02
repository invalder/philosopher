/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:55:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 01:49:28 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_meta	meta;

	if (argc < 5 || argc > 6)
		return (ft_handler(ERR_INPUT));
	if (ft_rules_init(&rules, argv, argc))
		return (ft_handler(ERR_FORMAT));
	ft_semaphore_destroy(&meta, &rules);
	if (ft_philo_init(&meta, &rules))
	{
		if (meta.philo_meta)
			free(meta.philo_meta);
		return (ft_handler(ERR_PHILO_INIT));
	}
	waitpid(-1, &meta.status, 0);
	if (meta.philo_id > 0)
		ft_kill_other_children(&meta, &rules);
	else
		free(meta.proc_list);
	if (!meta.proc_id && meta.philo_meta)
		free(meta.philo_meta);
	sem_close(rules.semaphore);
	sem_close(rules.actionsem);
	ft_semaphore_destroy(&meta, &rules);
	return (0);
}
