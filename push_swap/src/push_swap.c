/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:48:05 by shogura           #+#    #+#             */
/*   Updated: 2022/06/10 22:48:04 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	push_argv_to_stack(int len, char const *src[], t_stack **stack)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = NULL;
	while (i < len)
	{
		*stack = lstnew(ft_atoi(src[i]), -1);
		if (*stack == NULL)
			fail_to_allocate_mem(&tmp);
		if (i == 0)
			tmp = *stack;
		else
		{
			(*stack)->previous = tmp;
			tmp->next = *stack;
			tmp = *stack;
		}
		*stack = (*stack)->next;
		i++;
	}
	*stack = lstfisrt(tmp);
}

int	main(int argc, char const *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char const	**nums;

	stack_a = NULL;
	stack_b = NULL;
	nums = scan_args(argc, argv);
	if (nums == NULL)
		return (0);
	else if (nums == argv)
		push_argv_to_stack(argc - 1, &nums[1], &stack_a);
	else
	{
		argc = 0;
		while (nums[argc])
			argc++;
		push_argv_to_stack(argc, nums, &stack_a);
		free_nums((void **)nums);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
