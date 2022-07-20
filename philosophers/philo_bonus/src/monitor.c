/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:19:27 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 13:17:14 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	free_child_proc(t_status *status, int exit_status)
{
	free(status->philo.pid);
	exit(exit_status);
}

bool	check_eat_times(t_status *status, int *count)
{
	if (status->num_of_eat == 0)
		return (false);
	if (status->philo.eat_times == status->num_of_eat)
		(*count)++;
	if (*count == status->num_of_philo && status->num_of_philo != 1)
		return (true);
	return (false);
}

void	*death_monitor(void *arg)
{
	int				i;
	int				count;
	t_status		*status;
	size_t			now;

	status = (t_status *)arg;
	while (1)
	{
		count = 0;
		i = -1;
		while (++i < status->num_of_philo)
		{
			now = get_timestamp();
			if (now > status->philo.last_eat_time
				&& now - status->philo.last_eat_time > status->time_to_die)
			{
				print_action(DIE, status);
				sem_wait(status->print);
				free_child_proc(status, 1);
			}
			if (check_eat_times(status, &count))
				free_child_proc(status, 0);
		}
	}
	return (NULL);
}
