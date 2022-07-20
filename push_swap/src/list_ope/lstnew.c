/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:06:14 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 18:00:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*lstnew(int num, int index)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst == NULL)
		return (NULL);
	*lst = (t_stack){index, num, NULL, NULL};
	return (lst);
}
