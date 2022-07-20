/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:58:14 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 13:17:35 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

bool	take_fork(t_status *status)
{
	sem_wait(status->fork);
	print_action(FORK, status);
	if (status->num_of_philo == 1)
	{
		sem_post(status->fork);
		return (false);
	}
	sem_wait(status->fork);
	print_action(FORK, status);
	return (true);
}

void	eating(t_status *status)
{
	print_action(EAT, status);
	status->philo.last_eat_time = get_timestamp();
	status->philo.eat_times++;
	sleep_to_time(status->time_to_eat);
	sem_post(status->fork);
	sem_post(status->fork);
}

void	sleep_to_think(t_status *status)
{
	print_action(SLEEP, status);
	sleep_to_time(status->time_to_sleep);
	print_action(THINK, status);
}

void	*philo_life(t_status *status)
{
	if (pthread_create(&status->monitor, NULL, death_monitor, status))
		error_func(6);
	if (status->philo.id % 2 == 0)
		usleep(50);
	while (1)
	{
		if (status->num_of_eat != 0
			&& status->philo.eat_times == status->num_of_eat)
			return (NULL);
		if (!take_fork(status))
			break ;
		eating(status);
		sleep_to_think(status);
	}
	pthread_join(status->monitor, NULL);
	return (NULL);
}
