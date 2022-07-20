/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:58:33 by shogura           #+#    #+#             */
/*   Updated: 2022/06/21 23:54:40 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <utils.h>

// Message 現在時刻(ms) ID message
# define FORK "%lu %d has taken a fork\n"
# define EAT "%lu %d is eating\n"
# define SLEEP "%lu %d is sleeping\n"
# define THINK "%lu %d is thinking\n"
# define DIE "%lu %d is died\n"

typedef struct s_philo
{
	int					id;
	int					right_fork;
	int					left_fork;
	int					eat_times;
	size_t				last_eat_time;
	pthread_t			th;
	struct s_status		*status;
}	t_philo;

typedef struct s_status
{
	int				num_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	bool			break_flag;
	size_t			time_to_die;
	size_t			start_time;
	t_philo			*philo;
	pthread_t		check;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}	t_status;

bool	init_struct(int argc, char *argv[], t_status *status);
bool	init_mutex(t_status *status);
bool	create_thread_num_of_philo(t_status *status);
void	print_action(char *message, t_philo *philo, t_status *status);
void	*philo_life(void *arg);
void	*death_monitor(void *arg);
bool	error_func(int pattern);
void	free_all(t_status *status);
#endif
