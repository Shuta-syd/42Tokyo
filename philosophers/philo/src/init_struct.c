/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:34:59 by shogura           #+#    #+#             */
/*   Updated: 2022/06/20 15:39:01 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	allocate_mem_to_status(t_status *status)
{
	status->fork = malloc(sizeof(pthread_mutex_t) * (status->num_of_philo + 1));
	if (status->fork == NULL)
		return (error_func(3));
	status->philo = malloc(sizeof(t_philo) * status->num_of_philo);
	if (status->philo == NULL)
	{
		free(status->fork);
		return (error_func(3));
	}
	return (true);
}

void	store_args_in_status(int len, char *args[], t_status *status)
{
	int	i;

	i = 0;
	status->num_of_philo = ft_atoi(args[i++]);
	status->time_to_die = ft_atoi(args[i++]);
	status->time_to_eat = ft_atoi(args[i++]);
	status->time_to_sleep = ft_atoi(args[i++]);
	status->break_flag = false;
	status->num_of_eat = 0;
	if (len == 6)
		status->num_of_eat = ft_atoi(args[i]);
}

void	init_struct_philo(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		status->philo[i].id = i + 1;
		if (i == 0)
			status->philo[i].right_fork = status->num_of_philo - 1;
		else
			status->philo[i].right_fork = i - 1;
		status->philo[i].left_fork = i;
		status->philo[i].eat_times = 0;
		status->philo[i].status = status;
		i++;
	}
}

bool	init_struct(int argc, char *argv[], t_status *status)
{
	store_args_in_status(argc, argv, status);
	if (!allocate_mem_to_status(status))
		return (false);
	init_struct_philo(status);
	if (!init_mutex(status))
	{
		free_all(status);
		return (error_func(4));
	}
	return (true);
}
