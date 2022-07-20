/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:16:22 by shogura           #+#    #+#             */
/*   Updated: 2022/06/11 09:13:05 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_index(t_stack **stack, int len)
{
	int		i;
	int		min;
	t_stack	*tmp;
	t_stack	*min_list;

	i = 0;
	set_index_minus(stack);
	while (i < len)
	{
		tmp = *stack;
		min = INT_MAX;
		while (tmp)
		{
			if (tmp->num <= min && tmp->index == -1)
			{
				min = tmp->num;
				min_list = tmp;
			}
			tmp = tmp->next;
		}
		min_list->index = i;
		i++;
	}
}

void	set_index_minus(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

int	find_mid_point(t_stack *stack, int low, int high)
{
	int	sum;
	int	size;

	sum = 0;
	size = high - low;
	while (low++ < high && stack)
	{
		sum += stack->index;
		stack = stack->next;
	}
	return (sum / size);
}

bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	check_dup(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	while (stack->next)
	{
		while (tmp)
		{
			if (tmp->num == stack->num)
				return (false);
			tmp = tmp->next;
		}
		tmp = stack->next->next;
		stack = stack->next;
	}
	return (true);
}
