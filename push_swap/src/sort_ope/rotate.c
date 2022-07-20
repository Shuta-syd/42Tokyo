/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:23:25 by shogura           #+#    #+#             */
/*   Updated: 2022/06/02 16:26:18 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack **stack, bool both)
{
	t_stack	*top;
	t_stack	*last;

	top = lstfisrt(*stack);
	last = lstlast(*stack);
	top->next->previous = NULL;
	*stack = top->next;
	top->next = NULL;
	last->next = top;
	top->previous = last;
	if (!both)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack, bool both)
{
	t_stack	*top;
	t_stack	*last;

	top = lstfisrt(*stack);
	last = lstlast(*stack);
	top->next->previous = NULL;
	*stack = top->next;
	top->next = NULL;
	last->next = top;
	top->previous = last;
	if (!both)
		ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, true);
	rb(stack_b, true);
	ft_putstr("rr\n");
	return ;
}
