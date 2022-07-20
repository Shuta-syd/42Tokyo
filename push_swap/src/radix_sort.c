/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:46:51 by shogura           #+#    #+#             */
/*   Updated: 2022/06/04 15:50:52 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	maxbit_digits(t_stack *stack)
{
	int	max;
	int	digits;

	max = 0;
	digits = 0;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	while (max)
	{
		max /= 2;
		digits++;
	}
	return (digits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < maxbit_digits(*stack_a))
	{
		j = 0;
		count = 0;
		while (j < len)
		{
			if (((*stack_a)->index >> i & 1) == 0)
			{
				count++;
				pb(stack_a, stack_b);
			}
			else
				ra(stack_a, false);
			j++;
		}
		push_to_stack_a(stack_a, stack_b, count);
		i++;
	}
}
