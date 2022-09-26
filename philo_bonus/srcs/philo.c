/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:55:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 01:17:39 by nnakarac         ###   ########.fr       */
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
	ft_print_rules(&rules);
	if (ft_philo_init(&meta, &rules))
	{
		if (meta.philo_meta)
			free(meta.philo_meta);
		return (ft_handler(ERR_PHILO_INIT));
	}
	waitpid(-1, &meta.status, 0);
	if (!meta.proc_id && meta.philo_meta)
	{
		printf("Free Metamon\n");
		free(meta.philo_meta);
	}
	printf("This is the way\n");
	ft_kill_other_children(&meta, &rules);
	return (0);
}
