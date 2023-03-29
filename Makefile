# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 08:46:55 by jrenault          #+#    #+#              #
#    Updated: 2023/02/25 11:21:14 by jrenault         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all clear mkbuild lib mlx clean fclean re bonus

NAME					= so_long

BUILD_DIR				= build/
BUILD_DIR_BONUS			= build/
	
HEADER_DIR				= header/
HEADER_FILE				= so_long.h
HEADER_FILE_BONUS		= so_long_bonus.h
HEADERS_WITH_PATH		= $(addprefix $(HEADER_DIR),$(HEADER_FILE))
HEADERS_WITH_PATH_BONUS	= $(addprefix $(HEADER_DIR),$(HEADER_FILE_BONUS))

DIR						= src/
SRC			 			= 	main.c \
							deal_key.c \
							close_win.c \
							draw_map.c \
							map_parsing.c \
							check_error.c \
							check_error_bis.c \
							path_finding.c \
							move_player.c \
							init_sprites.c \
							is_game_over.c \
							init_game.c \
							init_param.c \
							free_param.c \

DIR_BONUS				= src_bonus/
SRC_BONUS			 	= 	main_bonus.c \
							deal_key_bonus.c \
							close_win_bonus.c \
							map_parsing_bonus.c \
							check_error_bonus.c \
							check_error_bis_bonus.c \
							path_finding_bonus.c \
							is_game_over_bonus.c \
							init_param_bonus.c \
							ft_fps.c \
							game_loop.c \
							show_move.c \
							init_sprites/init_sprites_bonus.c \
							init_sprites/init_imgs.c \
							init_sprites/init_sprites_map.c init_sprites/init_sprites_player_foe.c \
							free_param/free_param_bonus.c free_param/free_sprites_map.c \
							free_param/free_sprites_player.c free_param/free_sprites_foe.c \
							draw_map/draw_map_bonus.c \
							draw_map/draw_ground.c \
							draw_map/draw_wall.c draw_map/draw_wall_center.c draw_map/draw_wall_corners.c \
							draw_map/draw_player.c \
							draw_map/draw_foe.c \
							animation/player_idle_animation.c animation/foe_idle_animation.c \
							move_player/move_player_up.c \
							move_player/move_player_down.c \
							move_player/move_player_left.c \
							move_player/move_player_right.c \



OBJECTS			    	= ${addprefix ${BUILD_DIR},${SRC:.c=.o}}
OBJECTS_BONUS		   	= ${addprefix ${BUILD_DIR_BONUS},${SRC_BONUS:.c=.o}}
	
LIBFT					= libft.a
LIB_DIR					= ft_printf/libft/
FT_PRINTF				= libftprintf.a
PRINT_DIR				= ft_printf/
GET_NEXT_LINE			= get_next_line.a
GNL_DIR					= ft_printf/libft/get_next_line/
	
GCC						= cc
CFLAGS					= -Wall -Wextra -Werror -g

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= mlx/
LINUX					= -Lmlx -lmlx -Imlx -lXext -lX11 -lm


$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADERS_WITH_PATH} Makefile
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(MINILIB_DIR) -c $< -o $@

$(BUILD_DIR_BONUS)%.o:	$(DIR_BONUS)%.c ${HEADERS_WITH_PATH_BONUS} Makefile
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					mkbuild lib minilibx $(HEADER_DIR) $(NAME)
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE)
						$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE) -L$(MINILIB_DIR) $(LINUX) -lmlx

bonus:					lib minilibx $(OBJECTS_BONUS) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE)
						$(GCC) $(CFLAGS) $(OBJECTS_BONUS) -o so_long_bonus $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE) -L$(MINILIB_DIR) $(LINUX) -lmlx

lib:
						make -C $(LIB_DIR)
						make -C $(PRINT_DIR)
						make -C $(GNL_DIR)

minilibx:
						make -C $(MINILIB_DIR)
						
clean:					
						${RM} $(OBJECTS) $(OBJECTS_BONUS)
						make clean -C $(LIB_DIR)
						make clean -C $(MINILIB_DIR)
						make clean -C $(PRINT_DIR)
						make clean -C $(GNL_DIR)
						${RM} $(BUILD_DIR) $(BUILD_DIR_BONUS)

fclean:					clean
						${RM} ${NAME} so_long_bonus
						make fclean -C $(LIB_DIR)
						make fclean -C $(PRINT_DIR)
						make fclean -C $(GNL_DIR)

re:						fclean all
						$(MAKE) all