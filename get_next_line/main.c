/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:51 by shogura           #+#    #+#             */
/*   Updated: 2022/04/20 12:15:57 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void test(int fd)
{
	int index; //読み込み回数を確認する用
	char *receiver = NULL;
	index = 0;
	while (1)
	{
		receiver = get_next_line(fd);
		if (receiver == NULL)
		{
			printf("EOF or ERROR\n");
			break;
		}
		printf("[%d] -> %s\n", index, receiver);
		index++;
		free(receiver);
	}
}

int main(void)
{
	int	fd;

	char file_name[][100] = {
			"gnlTester/files/empty",
			"gnlTester/files/nl",
			"gnlTester/files/41_no_nl",
			"gnlTester/files/41_with_nl",
			"gnlTester/files/42_no_nl",
			"gnlTester/files/42_with_nl",
			"gnlTester/files/43_no_nl",
			"gnlTester/files/43_with_nl",
			"gnlTester/files/alternate_line_nl_no_nl",
			"gnlTester/files/alternate_line_nl_with_nl",
			"gnlTester/files/big_line_no_nl",
			"gnlTester/files/big_line_with_nl",
			"gnlTester/files/multiple_line_no_nl",
			"gnlTester/files/multiple_line_with_nl",
			"gnlTester/files/multiple_nlx5"
			};

	for (int i = 0; i < 14; i++)
	{
		fd = open(file_name[i], O_RDONLY);
		printf("==========================%s==========================\n\n", file_name[i]);
		test(fd);
		printf("==========================%s END==========================\n\n", file_name[i]);
	}
	return 0;
}
