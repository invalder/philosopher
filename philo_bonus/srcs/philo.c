/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:55:12 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/25 17:29:10 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;
	t_meta	meta;

	(void) meta;
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
	if (!meta.proc_id && meta.philo_meta)
	{
		printf("Free Metamon\n");
		free(meta.philo_meta);
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("Waiting for the child finished\n");
	}
	printf("PID %d closed\n", getpid());
	return (0);
}
