/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:13:07 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/27 22:58:25 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "color.h"

int	ft_rules_init(t_rules *rules, char **argv, int argc)
{
	struct timeval	tv;

	if (!ft_input_check(argv, argc))
	{
		rules->num_philo = ft_atoi(argv[1]);
		if (rules->num_philo < 1)
			return (1);
		rules->time_to_die = ft_atoi(argv[2]);
		rules->time_to_eat = ft_atoi(argv[3]);
		rules->time_to_sleep = ft_atoi(argv[4]);
		rules->is_alive = 1;
		rules->semaphore = sem_open("/philo_sem", O_CREAT, 0644, rules->num_philo);
		if (argc == 6)
		{
			rules->num_eat_time = ft_atoi(argv[5]);
			if (!rules->num_eat_time)
				return (1);
		}
		else
			rules->num_eat_time = -1;
		gettimeofday(&tv, NULL);
		rules->time_init = tv.tv_sec * 1000000 + tv.tv_usec;
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
