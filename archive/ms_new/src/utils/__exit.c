/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:37:56 by shogura           #+#    #+#             */
/*   Updated: 2022/07/13 18:39:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	terminate and reset all minishell processes
*/
void	__exit(int status)
{
	exit(status);
}
