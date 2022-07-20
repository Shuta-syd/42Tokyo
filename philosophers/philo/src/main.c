/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:09:03 by shogura           #+#    #+#             */
/*   Updated: 2022/06/18 22:22:56 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// __attribute__((destructor))
// static void destructor(void)
// {
// 	system("leaks -q philo");
// }

void	destroy_mutex(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		pthread_mutex_destroy(&status->fork[i]);
		i++;
	}
}

bool	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]) || ft_atoi(argv[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	start_philo(t_status *status)
{
	int			i;
	pthread_t	check;

	status->start_time = get_timestamp();
	if (!create_thread_num_of_philo(status))
	{
		free_all(status);
		return (error_func(5));
	}
	pthread_create(&check, NULL, death_monitor, status);
	pthread_mutex_unlock(&status->print);
	pthread_join(check, NULL);
	i = 0;
	while (i < status->num_of_philo)
		pthread_join(status->philo[i++].th, NULL);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_status	status;

	memset(&status, 0, sizeof(t_status));
	if (argc != 5 && argc != 6)
		return (error_func(1));
	if (!check_args(argc - 1, argv + 1))
		return (error_func(2));
	if (!init_struct(argc, argv + 1, &status))
		return (1);
	if (!start_philo(&status))
		return (1);
	destroy_mutex(&status);
	free_all(&status);
	return (0);
}
