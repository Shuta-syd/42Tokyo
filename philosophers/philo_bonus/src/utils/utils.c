/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:45:16 by shogura           #+#    #+#             */
/*   Updated: 2022/06/18 22:33:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

size_t	get_timestamp(void)
{
	size_t			timestamp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp);
}

void	sleep_to_time(size_t time)
{
	size_t	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(10);
}
