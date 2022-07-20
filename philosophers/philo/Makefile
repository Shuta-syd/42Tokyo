# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 20:06:49 by shogura           #+#    #+#              #
#    Updated: 2022/06/17 16:12:40 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -g -Wall -Wextra -Werror -pthread

INC = inc/

SRC_FILES = main.c philo.c error_handler.c init_struct.c thread_control.c monitor.c print_action.c
UTILS_FILES =${addprefix utils/, ft_atoi.c utils.c ft_isdigit.c ft_isnum.c}

SRC = ${addprefix src/, ${SRC_FILES} ${UTILS_FILES}}

OBJS = ${SRC:.c=.o}

RM = rm -rf

NR = norminette -R CheckForbiddenSourceHeader

all: ${NAME}

${NAME}:${OBJS}
	${CC} ${CFLAGS} -I${INC} -o $@ $^

.c.o:
	${CC} ${CFLAGS} -I${INC} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
