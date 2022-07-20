/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:26:13 by shogura           #+#    #+#             */
/*   Updated: 2022/06/15 16:29:19 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_action(char *message, t_philo *philo, t_status *status)
{
	if (status->break_flag)
		return ;
	pthread_mutex_lock(&status->print);
	printf(message, get_timestamp() - status->start_time, philo->id);
	pthread_mutex_unlock(&status->print);
}
