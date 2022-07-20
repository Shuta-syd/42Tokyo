/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:47:01 by shogura           #+#    #+#             */
/*   Updated: 2022/06/10 22:39:24 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_nums(void **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

static void	scan_nums(int len, char const *nums[])
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!check_min_max(ft_atol(nums[i])) || !ft_isnum(nums[i]))
		{
			free_nums((void **)nums);
			error_argv(2);
		}
		i++;
	}
}

char const	**split_args(const char *argv[])
{
	int			len;
	char const	**nums;

	len = 0;
	nums = (char const **)ft_split(argv[1], ' ');
	if (nums == NULL)
		fail_to_allocate_mem(NULL);
	else if (!ft_isnum(nums[0]))
	{
		free_nums((void **)nums);
		error_argv(2);
	}
	while (nums[len])
		len++;
	scan_nums(len, nums);
	return (nums);
}
