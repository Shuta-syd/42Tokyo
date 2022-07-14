# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/04/20 18:36:15 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out

CC=gcc

CFLAG= -g -Wall -Wextra -Werror

NR=norminette -R CheckForbiddenSourceHeader

SRCS=get_next_line.c get_next_line_utils.c

HEADER=get_next_line.h get_next_line_bonus.h

BONUS=get_next_line_bonus.c get_next_line_utils_bonus.c

all:${SRCS}
	${CC} ${CFLAG} -D BUFFER_SIZE=100000000 $^ main.c

bonus:${BONUS}
	${CC} ${CFLAG} -D BUFFER_SIZE=42 $^ main_bonus.c

nr:${SRCS} ${BONUS} ${HEADER}
	${NR} $^

fclean:
	rm -f ${NAME}

re: fclean all

#relink対策
#10000000（1千万）からセグフォ
#1000000まで正常に動く
