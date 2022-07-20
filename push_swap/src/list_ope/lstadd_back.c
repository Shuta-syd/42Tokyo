/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:08:07 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 17:49:25 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	else if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}
