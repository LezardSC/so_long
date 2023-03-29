/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:37 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:44:51 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/libft/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_draw
{
	void	*ground;
	void	*escape;
	void	*item_0;
	void	**wall_init;
	void	**player_idle_front;
	void	**player_idle_back;
	void	**player_idle_left;
	void	**player_idle_right;
	void	**foe_idle_front;
}			t_draw;

typedef struct s_data
{
	char		**map;
	void		*mlx;
	void		*win;
	int			line_length;
	int			max_x;
	int			max_y;
	int			nb_collectible;
	int			nb_c_tmp;
	int			nb_e_tmp;
	char		**map_tmp;
	char		*map_name;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	long		move_count;
	int			fps;
	long long	last_mtimestamp;
	char		player_direction;
	int			animation_frame;
	int			foe_idle_front_frame;
	int			player_idle_front_frame;
	int			player_idle_back_frame;
	int			player_idle_left_frame;
	int			player_idle_right_frame;
	int			end_game;
	t_draw		draw;
}			t_data;

int			main(int argc, char **argv);
int			deal_key(int key, t_data *param);
int			close_win(t_data *param);
int			init_sprites(t_data *param);
int			map_parsing(t_data *param, int i);
int			check_error(t_data *param);
int			check_map(t_data *param);
int			check_factors(t_data *param, int i, int j);
int			check_walls(t_data *param);
int			check_path(t_data *param);
void		copy_map(t_data *param);
void		path_finding(t_data *param, int x, int y);
void		update_backtrack(t_data *param, int x, int y);
int			move_up(t_data *param);
int			move_left(t_data *param);
int			move_down(t_data *param);
int			move_right(t_data *param);
int			is_game_over(t_data *param);
int			init_param(t_data *param);

///////////////////////
/////////BONUS/////////
///////////////////////

void		ft_fps(t_data *param);
void		show_fps(t_data *param);
int			game_loop(t_data *param);
long long	millitimestamp(void);
int			show_move(t_data *param);
int			deal_attack(t_data *param);

//initialize sprites

void		**init_imgs(t_data *param,
				const char *img_path, int nb_imgs, int n);
void		*join_path_name(const char *img_path, char *char_n);
int			init_sprites_map(t_data *param);
int			init_sprites_player_foe(t_data *param);

// free param

int			free_init(t_data *param);
int			free_all_param(t_data *param);
void		free_sprites_map(t_data *param);
void		free_sprites_player(t_data *param);
void		free_sprites_player_2(t_data *param);
void		free_sprites_foe(t_data *param);

// draw

int			draw_all(t_data *param);
int			draw_map(t_data *param);
int			draw_player(t_data *param);
int			draw_items(t_data *param);
int			draw_exit(t_data *param);
int			draw_player(t_data *param);
int			draw_foe(t_data *param);
int			draw_ground(t_data *param, int x, int y);
void		draw_wall_up_left(t_data *param, int x, int y);
void		draw_wall_up_right(t_data *param, int x, int y);
void		draw_wall_down_left(t_data *param, int x, int y);
void		draw_wall_down_right(t_data *param, int x, int y);
void		draw_wall_left(t_data *param, int x, int y);
void		draw_wall_right(t_data *param, int x, int y);
void		draw_wall_up(t_data *param, int x, int y);
void		draw_wall_down(t_data *param, int x, int y);
void		draw_wall_center(t_data *param, int x, int y);
void		draw_wall_cross(t_data *param, int x, int y);
void		draw_wall_semi_cross(t_data *param, int x, int y);

// animate

int			foe_idle_animation_front(t_data *param, int x, int y);
int			player_idle_animation_front(t_data *param, int x, int y);
int			player_idle_animation_back(t_data *param, int x, int y);
int			player_idle_animation_left(t_data *param, int x, int y);
int			player_idle_animation_right(t_data *param, int x, int y);

#endif