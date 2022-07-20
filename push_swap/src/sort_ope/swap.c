/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:23:17 by shogura           #+#    #+#             */
/*   Updated: 2022/06/04 15:18:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_stack **stack, bool both)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if ((*stack)->next)
		(*stack)->next->previous = tmp;
	if (!both)
		ft_putstr("sa\n");
}

void	sb(t_stack **stack, bool both)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if ((*stack)->next)
		(*stack)->next->previous = tmp;
	if (!both)
		ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, true);
	sb(stack_b, true);
	ft_putstr("ss\n");
	return ;
}
