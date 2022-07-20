/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:30:46 by shogura           #+#    #+#             */
/*   Updated: 2022/07/15 14:38:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q minishell");
}


int	main(int argc, char *argv[], char **envp)
{
	t_shell	data;

	data = (t_shell){};
	store_env_lst(&data, envp);
	while (42)
	{
		user_input(&data);
		lexer(&data);
	}
	return (0);
}
