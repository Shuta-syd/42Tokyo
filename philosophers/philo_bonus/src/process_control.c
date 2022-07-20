/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:43:37 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 12:55:37 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	kill_process(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		kill(status->philo.pid[i], SIGKILL);
		i++;
	}
}

void	child_process_action(t_status *status, int id)
{
	status->philo.id = id;
	status->philo.last_eat_time = status->start_time;
	philo_life(status);
}

void	start_process(t_status *status)
{
	int	i;
	int	wait_status;

	i = 0;
	wait_status = 0;
	status->start_time = get_timestamp();
	while (i < status->num_of_philo)
	{
		status->philo.pid[i] = fork();
		if (status->philo.pid[i] == FORK_FAILED)
		{
			free_all(status);
			error_func(7);
		}
		if (status->philo.pid[i] == CHILD_PROCESS)
			return (child_process_action(status, i + 1));
		i++;
	}
	while (waitpid(-1, &wait_status, 0) > 0)
	{
		if (WIFEXITED(wait_status))
			kill_process(status);
	}
	return ;
}
