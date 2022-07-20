/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:27:49 by shogura           #+#    #+#             */
/*   Updated: 2022/07/13 20:07:56 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	1. use ';' as a delimiter to separate the command line.
	2. Separate the command line into each strings and store them in t_cmd
	Grammar error checking to follow
*/
void	lexer(t_data *data)
{
	int		i;
	int		len;
	char	**cmdline;

	i = 0;
	cmdline = ft_split(data->input, ';');
	malloc_error_check((void *)cmdline);
	len = count_cmdline(cmdline);
	data->cmd_lst = ft_calloc(len, sizeof(t_cmd *));
	malloc_error_check((void *)cmdline);
	while (cmdline[i])
	{
		export_to_cmd_lst(data, cmdline[i]);
		i++;
	}
}
void store_cmd_lst(t_data *data, char *cmdline)
{
	t_cmd	*node;
	int		num;

	num = 0;
	while (*cmdline)
	{
		node = fetch_str_from_cmdline(&cmdline, &num);
		cmd_lst_add_back(data, node);
	}
}

t_cmd	*fetch_str_from_cmdline(char **cmdline, int *type)
{
	char	*cp_cmdline;
	t_cmd	*node;
	int		len;

	len = 0;
	cp_cmdline = *cmdline;
	while (**cmdline)
	{
		if (ft_strchr(META_STR, **cmdline))
			break ;
		(*cmdline)++;
		len++;
	}
	if (*type == 0)
		node = cmd_lst_new1(cp_cmdline, len);
	else
		node = cmd_lst_new2(cp_cmdline, len);
	malloc_error_check((void *)node);
	return (node);
}
