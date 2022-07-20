/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:58:14 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 00:16:02 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	take_fork(t_status *status, t_philo *philo)
{
	if (status->break_flag)
		return (false);
	pthread_mutex_lock(&status->fork[philo->left_fork]);
	print_action(FORK, philo, status);
	if (status->num_of_philo == 1)
	{
		pthread_mutex_unlock(&status->fork[philo->left_fork]);
		return (false);
	}
	pthread_mutex_lock(&status->fork[philo->right_fork]);
	print_action(FORK, philo, status);
	return (true);
}

bool	eating(t_status *status, t_philo *philo)
{
	if (status->break_flag)
		return (false);
	print_action(EAT, philo, status);
	philo->last_eat_time = get_timestamp();
	philo->eat_times++;
	sleep_to_time(status->time_to_eat);
	pthread_mutex_unlock(&status->fork[philo->left_fork]);
	pthread_mutex_unlock(&status->fork[philo->right_fork]);
	return (true);
}

void	sleeping(t_status *status, t_philo *philo)
{
	if (status->break_flag)
		return ;
	print_action(SLEEP, philo, status);
	sleep_to_time(status->time_to_sleep);
}

void	thinking(t_status *status, t_philo *philo)
{
	if (status->break_flag)
		return ;
	print_action(THINK, philo, status);
}

void	*philo_life(void *arg)
{
	t_status	*status;
	t_philo		*philo;

	philo = (t_philo *)arg;
	status = (t_status *)philo->status;
	if (philo->id % 2 == 0)
	{
		print_action(THINK, philo, status);
		usleep(50);
	}
	while (!status->break_flag)
	{
		if (status->num_of_eat != 0
			&& philo->eat_times == status->num_of_eat)
			return (NULL);
		if (!take_fork(status, philo))
			break ;
		if (!eating(status, philo))
			break ;
		sleeping(status, philo);
		thinking(status, philo);
	}
	pthread_mutex_unlock(&status->fork[philo->left_fork]);
	pthread_mutex_unlock(&status->fork[philo->right_fork]);
	return (NULL);
}
