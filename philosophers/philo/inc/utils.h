/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:01:19 by shogura           #+#    #+#             */
/*   Updated: 2022/06/15 16:24:56 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

//utils function
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isnum(char const *str);
size_t	get_timestamp(void);
void	sleep_to_time(size_t time);
#endif
