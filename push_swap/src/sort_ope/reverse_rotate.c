/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:23:25 by shogura           #+#    #+#             */
/*   Updated: 2022/06/03 21:30:49 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_stack **stack, bool both)
{
	t_stack	*top;
	t_stack	*last;

	top = lstfisrt(*stack);
	last = lstlast(*stack);
	*stack = last;
	last->previous->next = NULL;
	(*stack)->previous = NULL;
	top->previous = last;
	last->next = top;
	if (!both)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack, bool both)
{
	t_stack	*top;
	t_stack	*last;

	top = lstfisrt(*stack);
	last = lstlast(*stack);
	*stack = last;
	(*stack)->previous = NULL;
	top->previous = last;
	last->next = top;
	if (!both)
		ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, true);
	rrb(stack_b, true);
	ft_putstr("rrr\n");
	return ;
}
