/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:06:34 by shogura           #+#    #+#             */
/*   Updated: 2022/06/18 22:20:27 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_all(t_status *status)
{
	free(status->fork);
	free(status->philo);
}

bool	error_func(int pattern)
{
	if (pattern == 1)
		printf("ERROR\nToo few or many args\n");
	else if (pattern == 2)
		printf("ERROR\nInvalid argument\n");
	else if (pattern == 3)
		printf("ERROR\nFailed to allocate mem\n");
	else if (pattern == 4)
		printf("ERROR\nFailed to create mutex\n");
	else if (pattern == 5)
		printf("ERROR\nFailed to create thread\n");
	return (false);
}
