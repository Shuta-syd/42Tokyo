/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:56:36 by shogura           #+#    #+#             */
/*   Updated: 2022/07/13 20:09:48 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Function to create cmd_lst with the first str of the cmdline or the first str after the pipe
*/
t_cmd *cmd_lst_new1(char *str , int len)
{
	t_cmd	*node;
	node = ft_calloc(1, sizeof(t_cmd));
	if (node == NULL)
		return (NULL);
	node->cmd = ft_substr(str, 0, len);
	if (node->cmd == NULL)
	{
		free(node);
		return (NULL);
	}
	node->type = T_CMD;
	node->args = NULL;
	node->next = NULL;
	return (node);
}

/*
	other than cmd_lst_new1()
	argをどのように分けるか->execve()の第1引数次第
*/
t_cmd *cmd_lst_new2(char *str, int len)
{
	t_cmd *node;
	node = ft_calloc(1, sizeof(t_cmd));
	if (node == NULL)
		return (NULL);
	node->cmd = ft_substr(str, 0, len);
	if (node->cmd == NULL)
	{
		free(node);
		return (NULL);
	}
	node->type = T_ARG;
	node->args = NULL;
	node->next = NULL;
	return (node);
}
