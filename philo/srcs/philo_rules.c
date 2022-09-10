/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:13:07 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/10 17:42:00 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_rules_init(t_rules *rules, char **argv, int argc)
{
	if (!ft_input_check(argv, argc))
	{
		rules->num_philo = ft_atoi(argv[1]);
		rules->time_to_die = ft_atoi(argv[2]);
		rules->time_to_eat = ft_atoi(argv[3]);
		rules->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			rules->num_eat_time = ft_atoi(argv[5]);
		else
			rules->num_eat_time = -1;
		return (0);
	}
	return (1);
}

void	ft_print_rules(t_rules *rules)
{
	printf("number of philo: %d\n", rules->num_philo);
	printf("time to die: %d\n", rules->time_to_die);
	printf("time to eat: %d\n", rules->time_to_eat);
	printf("time to sleep: %d\n", rules->time_to_sleep);
	printf("number eat time: %d\n", rules->num_eat_time);
}

int	ft_input_check(char **argv, int argc)
{
	if (ft_isdigit_str(argv[1]) || ft_isdigit_str(argv[2]) || \
		ft_isdigit_str(argv[3]) || ft_isdigit_str(argv[4]))
		return (1);
	if (argc == 6 && ft_isdigit_str(argv[5]))
		return (1);
	return (0);
}
