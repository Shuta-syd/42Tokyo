/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:26:13 by shogura           #+#    #+#             */
/*   Updated: 2022/06/18 18:19:57 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_action(char *message, t_status *status)
{
	sem_wait(status->print);
	printf(message, get_timestamp() - status->start_time, status->philo.id);
	sem_post(status->print);
}
