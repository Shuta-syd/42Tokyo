/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:59:08 by shogura           #+#    #+#             */
/*   Updated: 2022/06/04 15:45:16 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char const *str)
{
	if (*str == '-')
		str++;
	else if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}
