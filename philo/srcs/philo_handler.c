/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:53:02 by nnakarac          #+#    #+#             */
/*   Updated: 2022/09/15 00:33:56 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t		ret;
	const char	*ptr;

	ret = 0;
	ptr = s;
	if (s)
	{
		while (*ptr++)
			ret++;
	}
	return (ret);
}

void	ft_print_error(const char *str)
{
	write(2, str, ft_strlen(str));
}

int	ft_handler(int err_code)
{
	if (err_code == ERR_INPUT)
	{
		ft_print_error("Input may be wrong, Please follow these below!!!\n");
		ft_print_error("number_of_philosophers time_to_die time_to_eat ");
		ft_print_error("time_to_sleep ");
		ft_print_error("[number_of_times_each_philosopher_must_eat]\n");
	}
	else if (err_code == ERR_FORMAT)
	{
		ft_print_error("Input may be in wrong, Please make sure that ");
		ft_print_error("your inputs are in positive integer\n");
		ft_print_error("number of philosopher must greater than 0\n");
	}
	else if (err_code == ERR_PHILO_INIT)
		ft_print_error("Failure to init Philosopher!!!\n");
	else
		ft_handler2(err_code);
	return (err_code);
}

int	ft_handler2(int err_code)
{
	return (err_code);
}
