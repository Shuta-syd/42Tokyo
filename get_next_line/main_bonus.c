/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:51 by shogura           #+#    #+#             */
/*   Updated: 2022/04/20 18:45:07 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int i = 0; //読み込み回数を確認する用
	char *receiver = NULL;
	int	fd1;
	int fd2;
	int fd3;
	int fd4;

	char file_name[][100] = {
			"gnlTester/files/41_with_nl",
			"gnlTester/files/42_with_nl",
			"gnlTester/files/43_with_nl",
			"gnlTester/files/alternate_line_nl_with_nl",
	};

	fd1 = open(file_name[0], O_RDONLY);
	fd2 = open(file_name[1], O_RDONLY);
	fd3 = open(file_name[2], O_RDONLY);
	fd4 = open(file_name[2], O_RDONLY);
	printf("==========================MUSTIPLE==========================\n\n");
	//1
	receiver = get_next_line(fd1);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);
	receiver = get_next_line(fd2);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);
	receiver = get_next_line(fd3);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);

	//2
	receiver = get_next_line(fd1);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);
	receiver = get_next_line(fd2);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);
	receiver = get_next_line(fd3);
	if (receiver == NULL)
		printf("EOF or ERROR\n");
	else
		printf("[%d] -> %s\n", i, receiver);
	printf("PASS\n");
	i++;
	free(receiver);
	printf("=============================END============================\n\n");
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return 0;
}
