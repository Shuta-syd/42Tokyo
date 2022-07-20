/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:58:33 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 13:17:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <utils.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <semaphore.h>

# define FORK_FAILED -1
# define CHILD_PROCESS 0
# define FORK "%lu %d has taken a fork\n"
# define EAT "%lu %d is eating\n"
# define SLEEP "%lu %d is sleeping\n"
# define THINK "%lu %d is thinking\n"
# define DIE "%lu %d is died\n"

typedef struct s_philo
{
	int			id;
	int			eat_times;
	bool		death_flag;
	size_t		last_eat_time;
	pid_t		*pid;
}	t_philo;

typedef struct s_status
{
	int			num_of_philo;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eat;
	size_t		start_time;
	size_t		time_to_die;
	pthread_t	monitor;
	t_philo		philo;
	sem_t		*fork;
	sem_t		*print;
}	t_status;

bool	init_struct(int argc, char *argv[], t_status *status);
void	start_process(t_status *status);
void	*philo_life(t_status *status);
void	print_action(char *message, t_status *status);
void	*death_monitor(void	*arg);
void	error_func(int pattern);
void	free_all(t_status *status);
void	free_child_proc(t_status *status, int exit_status);
#endif
