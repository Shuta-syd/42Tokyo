/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:23:52 by shogura           #+#    #+#             */
/*   Updated: 2022/06/17 16:34:18 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	create_thread_num_of_philo(t_status *status)
{
	int		i;

	i = 0;
	while (i < status->num_of_philo)
	{
		if (pthread_create(&status->philo[i].th, NULL,
				&philo_life, &status->philo[i]))
			return (false);
		status->philo[i].last_eat_time = get_timestamp();
		i++;
	}
	return (true);
}

bool	create_mutex_num_of_fork(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		if (pthread_mutex_init(&status->fork[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&status->print, NULL))
		return (false);
	return (true);
}

bool	init_mutex(t_status *status)
{
	if (!create_mutex_num_of_fork(status))
		return (false);
	return (true);
}
