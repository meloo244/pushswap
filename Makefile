# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 19:16:30 by mmarie            #+#    #+#              #
#    Updated: 2023/10/14 14:14:25 by mmarie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = check

SRCS =  $(wildcard src/*.c utils/*.c mouvement/*.c)
CHECK_SRCS = $(wildcard utils/*.c gnl/*.c mouvement_checker/*.c) checker/checker.c src/other.c src/sort.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: ${CHECKER}
${CHECKER}: ${CHECK_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECKER}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
