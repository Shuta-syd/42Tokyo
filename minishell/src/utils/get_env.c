/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:40:08 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/18 19:18:51 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ms_getenv(t_shell *data, char *name)
{
	t_env *env_lst;

	env_lst = data->env_lst;
	while (env_lst)
	{
		if (ft_strcmp(env_lst->key, name) == 0)
			return (env_lst->val);
		env_lst = env_lst->next;
	}
	return ("");
}
