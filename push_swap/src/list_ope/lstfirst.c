/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:44:00 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 17:50:23 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*lstfisrt(t_stack *stack)
{
	t_stack	*first;

	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		first = stack;
		stack = stack->previous;
		if (stack == NULL)
			break ;
	}
	return (first);
}
