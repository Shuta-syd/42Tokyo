/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:41:40 by shogura           #+#    #+#             */
/*   Updated: 2022/06/13 21:10:09 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	elem3_sort(t_stack **stack)
{
	while (!is_sorted(*stack))
	{
		if ((*stack)->index == 1 && (*stack)->next->index == 0)
			sa(stack, false);
		else if (((*stack)->index == 0 && (*stack)->next->index == 2)
			|| ((*stack)->index == 1 && (*stack)->next->index == 2))
			rra(stack, false);
		else
			ra(stack, false);
	}
}

void	elem5_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		mid;
	int		count;

	count = 2;
	mid = find_mid_point(*stack_a, 0, len);
	while (count > 0)
	{
		if ((*stack_a)->index > mid)
		{
			pb(stack_a, stack_b);
			count--;
		}
		else
			ra(stack_a, false);
	}
	set_index(stack_a, len - 2);
	elem3_sort(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b, false);
	while (*stack_b)
		pa(stack_a, stack_b);
	set_index(stack_a, len);
	while (!is_sorted(*stack_a))
		ra(stack_a, false);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	if (!check_dup(*stack_a))
	{
		ft_putstr_fd("ERROR\nNot int type or duplicate\n", 2);
		return ;
	}
	len = lstsize(*stack_a);
	set_index(stack_a, len);
	if (is_sorted(*stack_a))
		return ;
	if (len == 2)
		sa(stack_a, false);
	else if (len == 3)
		elem3_sort(stack_a);
	else if (len <= 5)
		elem5_sort(stack_a, stack_b, len);
	else if (len > 5)
		radix_sort(stack_a, stack_b, len);
	return ;
}
