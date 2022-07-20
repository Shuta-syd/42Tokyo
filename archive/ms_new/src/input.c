/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:55 by shogura           #+#    #+#             */
/*   Updated: 2022/07/13 19:00:05 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	user_input(t_data *data)
{
	char	*input;

	input = readline(PROMPT);
	if (input == NULL)
		ctrl_d();
	data->input = ft_strtrim(input, ' ');
	free(input);
	if (ft_strlen(data->input) > 0)
		add_history(data->input);
	return ;
}
