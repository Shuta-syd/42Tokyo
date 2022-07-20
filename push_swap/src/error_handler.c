/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:09 by shogura           #+#    #+#             */
/*   Updated: 2022/06/07 16:46:39 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	fail_to_allocate_mem(t_stack **stack)
{
	t_stack	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->previous;
		free(*stack);
		*stack = tmp;
	}
	ft_putstr_fd("ERROR\nFailed to malloc mem", 2);
	exit(1);
}

void	error_argv(int pattern)
{
	if (pattern == 1)
		ft_putstr_fd("ERROR\nToo few args\n", 2);
	else if (pattern == 2)
		ft_putstr_fd("ERROR\nNot int type or duplicate\n", 2);
	exit(1);
}
