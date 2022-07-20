/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:51:17 by shogura           #+#    #+#             */
/*   Updated: 2022/06/22 12:42:33 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

// __attribute__((destructor))
// static void destructor(void)
// {
// 	system("leaks -q philo_bonus");
// }

void	free_all(t_status *status)
{
	sem_unlink("print");
	sem_unlink("/fork");
	sem_close(status->fork);
	sem_close(status->print);
	free(status->philo.pid);
}

void	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]) || ft_atoi(argv[i]) == 0)
			error_func(2);
		i++;
	}
	return ;
}

bool	init_sem(t_status *status)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	status->print = sem_open("/print", O_CREAT, S_IRUSR, 1);
	if (status->print == SEM_FAILED)
	{
		free(status->philo.pid);
		error_func(5);
	}
	status->fork = sem_open("/fork", O_CREAT, S_IRUSR, status->num_of_philo);
	if (status->fork == SEM_FAILED)
	{
		sem_close(status->print);
		free(status->philo.pid);
		error_func(5);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_status	status;

	memset(&status, 0, sizeof(t_status));
	if (argc != 5 && argc != 6)
		error_func(1);
	check_args(argc - 1, argv + 1);
	init_struct(argc, argv + 1, &status);
	init_sem(&status);
	start_process(&status);
	free_all(&status);
	return (0);
}
