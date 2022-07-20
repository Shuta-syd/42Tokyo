/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:23:21 by shogura           #+#    #+#             */
/*   Updated: 2022/06/04 15:10:59 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = lstfisrt(*stack_a);
	top_b = lstfisrt(*stack_b);
	*stack_a = top_b;
	*stack_b = top_b->next;
	if (top_b->next != NULL)
		top_b->next->previous = NULL;
	top_b->previous = NULL;
	if (top_a == NULL)
		top_b->next = NULL;
	else
	{
		top_b->next = top_a;
		top_a->previous = top_b;
	}
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = lstfisrt(*stack_a);
	top_b = lstfisrt(*stack_b);
	*stack_b = top_a;
	*stack_a = top_a->next;
	(*stack_a)->previous = NULL;
	(*stack_b)->previous = NULL;
	if (top_b == NULL)
		(*stack_b)->next = NULL;
	else
	{
		(*stack_b)->next = top_b;
		top_b->previous = *stack_b;
	}
	ft_putstr("pb\n");
}
