# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 08:29:24 by jrenault          #+#    #+#              #
#    Updated: 2022/12/14 08:32:06 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: bonus all clean fclean re

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror
SANITFLAG = -Wall -Wextra -Werror -g -fsanitize=address
HEAD = libft.h

LIB = ar rc

RM = rm -f

%.o:		%.c ${HEAD} Makefile
			${CC} ${FLAGS} -include${HEAD} -c $< -o $@

${NAME}: 	${OBJS} Makefile
			${LIB} ${NAME} ${OBJS}

sanit:		$(OBJS) main.c
			${CC} ${SANITFLAG} $(OBJS) main.c

all:		${NAME} Makefile

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
