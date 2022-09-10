/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:14:39 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/10 17:28:53 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (ft_handler(ERR_PHILO_INIT));
	return (0);
}
