/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:11:59 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/13 19:18:32 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "minishell.h"

//input
void user_input(t_data *data);

//lexer
int count_cmd_line(char **input);
void export_to_cmd_lst(t_data *data, char *cmd_line);
void lexer(t_data *data);

// signals
void ctrl_d(void);
void set_signal(void);

// env_lst func
void store_env_lst(t_data *data, char **envp);

//utils
void __exit(int status);
void malloc_error_check(void *mem);
#endif
