/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:47:29 by shogura           #+#    #+#             */
/*   Updated: 2022/06/10 22:39:45 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	check_min_max(long num)
{
	if (num > (long)INT_MAX || num < (long)INT_MIN)
		return (false);
	return (true);
}

// check args error
char const	**scan_args(int argc, char const *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
		return (split_args(argv));
	while (i < argc)
	{
		if (!check_min_max(ft_atol(argv[i])) || !ft_isnum(argv[i]))
			error_argv(2);
		i++;
	}
	return (argv);
}
