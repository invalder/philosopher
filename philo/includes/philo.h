/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:37:45 by nnakarac          #+#    #+#             */
/*   Updated: 2022/10/03 00:21:30 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>

enum e_handler
{
	ERR_INPUT = 1,
	ERR_FORMAT = 2,
	ERR_PHILO_INIT = 3,
};

typedef struct s_rules
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat_time;
	int				is_alive;
	size_t			time_init;
	pthread_mutex_t	printer;
}	t_rules;

typedef struct s_philo
{
	int				philo_num;
	int				is_alive;
	int				eat_allow;
	int				time_to_eat;
	size_t			last_eat;
	size_t			last_sleep;
	pthread_mutex_t	fork_right;
	pthread_t		philosopher;
	pthread_t		philo_timer;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	time_key;
	t_rules			*rule;
}	t_philo;

typedef struct s_meta
{
	t_philo			*philo_meta;
}	t_meta;

int		ft_isspace(int c);
int		ft_atoi(const char *nptr);
size_t	ft_atost(const char *nptr);

int		ft_rules_init(t_rules *rules, char **argv, int argc);
void	ft_print_rules(t_rules *rules);
int		ft_input_check(char **argv, int argc);
int		ft_isdigit_str(char *ptr);
int		ft_isdigit(int c);

size_t	ft_strlen(const char *s);
void	ft_print_error(const char *str);
int		ft_handler(int err_code);
int		ft_handler2(int err_code);

int		ft_philo_meta_init_first(t_meta *meta, t_rules *rules);
int		ft_philo_meta_init(t_meta *meta, t_rules *rules);
int		ft_philo_create(t_meta *meta, t_rules *rules, int num_philo);
int		ft_philo_join(t_meta *meta, t_rules *rules);

int		ft_philo_timer_create(t_meta *meta, t_rules *rules);
int		ft_philo_timer_join(t_meta *meta, t_rules *rules);

int		ft_philo_init(t_meta *meta, t_rules *rules);

void	*ft_philo_routine(t_philo *philo);
void	*ft_philo_routine2(t_philo *philo);
void	*ft_philo_timer_routine(t_philo *philo);

int		ft_philo_fork_left(t_philo *philo);
int		ft_philo_fork_right(t_philo *philo);
int		ft_philo_eat(t_philo *philo);
int		ft_philo_sleep(t_philo *philo);
int		ft_philo_think(t_philo *philo);
int		ft_philo_countdownt_philo(t_philo *philo);

int		ft_philo_starving(t_philo *philo);

size_t	ft_current_time(t_rules *rules);
size_t	ft_current_time_rel(size_t current_time, t_rules *rules);
size_t	ft_conv_us_ms(size_t current_time);
void	ft_myusleep(size_t	time);

#endif
