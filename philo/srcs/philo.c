/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:14:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/02 19:43:02 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
	if (ft_philo_init(&meta, &rules))
	{
		if (meta.philo_meta)
			free(meta.philo_meta);
		return (ft_handler(ERR_PHILO_INIT));
	}
	if (meta.philo_meta)
		free(meta.philo_meta);
	return (0);
}
