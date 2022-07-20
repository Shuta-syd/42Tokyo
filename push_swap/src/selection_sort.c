/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:13:15 by shogura           #+#    #+#             */
/*   Updated: 2022/06/04 15:33:22 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*find_min_index_list(t_stack *stack)
{
	t_stack	*minlst;

	minlst = stack;
	while (stack)
	{
		if (minlst->index > stack->index)
			minlst = stack;
		stack = stack->next;
	}
	return (minlst);
}

void	index_is_top_or_last(t_stack *stack, int index, bool *top)
{
	int		count1;
	int		count2;
	t_stack	*last;

	count1 = 0;
	count2 = 0;
	last = lstlast(stack);
	while (stack)
	{
		if (stack->index == index)
			break ;
		count1++;
		stack = stack->next;
	}
	while (last)
	{
		if (last->index == index)
			break ;
		count2++;
		last = last->previous;
	}
	if (count1 > count2)
		*top = true;
	else
		*top = false;
}

void	move_minlst_to_top(t_stack **stack_a, int index)
{
	while (*stack_a != NULL && (*stack_a)->index != index)
		ra(stack_a, false);
}

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		pa(stack_a, stack_b);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		move_minlst_to_top(stack_a, index);
		pb(stack_a, stack_b);
		index++;
	}
	push_to_stack_a(stack_a, stack_b, len);
}
