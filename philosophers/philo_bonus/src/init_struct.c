/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:34:59 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 13:17:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	allocate_mem_to_status(t_status *status)
{
	status->philo.pid = malloc(sizeof(pid_t) * (status->num_of_philo));
	if (status->philo.pid == NULL)
		error_func(3);
	return ;
}

void	store_args_in_status(int len, char *args[], t_status *status)
{
	int	i;

	i = 0;
	status->philo = (t_philo){};
	status->num_of_philo = ft_atoi(args[i++]);
	status->time_to_die = ft_atoi(args[i++]);
	status->time_to_eat = ft_atoi(args[i++]);
	status->time_to_sleep = ft_atoi(args[i++]);
	status->num_of_eat = 0;
	if (len == 6)
		status->num_of_eat = ft_atoi(args[i]);
}

bool	init_struct(int argc, char *argv[], t_status *status)
{
	store_args_in_status(argc, argv, status);
	allocate_mem_to_status(status);
	return (true);
}
