/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:14:32 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 17:49:48 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*last;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		last = lst;
		lst = lst->next;
		if (lst == NULL)
			break ;
	}
	return (last);
}
