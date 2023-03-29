# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 08:55:21 by jrenault          #+#    #+#              #
#    Updated: 2022/11/28 08:57:07 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re rsc

NAME  = libftprintf.a

LIBFT = libft/libft.a

SRCS = ft_printf.c search_arg.c ispercent_x.c ispercent_capx.c ispercent_p.c ispercent_c.c ispercent_d_i.c ispercent_u.c ispercent_s.c
OBJS = ${SRCS:.c=.o}

HEADER = ft_printf.h\

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ar rc

RM = rm -f

all: rsc ${NAME}

rsc:
	@make -C libft

%.o:  %.c $(HEADER) Makefile
	 $(CC) ${FLAGS} -include${HEADER} -c $< -o $@


$(NAME):	$(OBJS) $(LIBFT)
		 cp $(LIBFT) $(NAME)
		 ${LIB} ${NAME} ${OBJS} libftprintf.a

clean:
		 ${RM} ${OBJS}
		 $(MAKE) clean -C libft

fclean: clean
	 	${RM} ${NAME}
		$(MAKE) fclean -C libft
re:	 fclean all