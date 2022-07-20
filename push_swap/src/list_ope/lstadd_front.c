/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:08:07 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 17:50:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	new->next = tmp;
	*lst = new;
	return ;
}
