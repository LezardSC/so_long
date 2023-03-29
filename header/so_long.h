/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:37 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:16:12 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/libft/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_draw
{
	void	*ground;
	void	*wall_center;
	void	*escape;
	void	*item;
	void	*player;
}			t_draw;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		line_length;
	int		max_x;
	int		max_y;
	int		nb_collectible;
	int		nb_c_tmp;
	int		nb_e_tmp;
	char	**map_tmp;
	char	*map_name;
	int		p_x;
	int		p_y;
	long	move_count;
	t_draw	draw;
}			t_data;

int		main(int argc, char **argv);
int		deal_key(int key, t_data *param);
int		close_win(t_data *param);
int		init_sprites(t_data *param);
int		init_player(t_data *param);
int		draw_map(t_data *param);
int		draw_items_exit(t_data *param);
int		draw_player(t_data *param);
int		map_parsing(t_data *param, int i);
int		check_error(t_data *param);
int		check_map(t_data *param);
int		check_factors(t_data *param, int i, int j);
int		check_walls(t_data *param);
int		check_path(t_data *param);
void	copy_map(t_data *param);
void	path_finding(t_data *param, int x, int y);
void	update_backtrack(t_data *param, int x, int y);
int		draw_all(t_data *param);
int		move_up(t_data *param);
int		move_left(t_data *param);
int		move_down(t_data *param);
int		move_right(t_data *param);
int		is_game_over(t_data *param);
int		init_game(t_data *param);
int		free_init(t_data *param);
int		free_all_param(t_data *param);
int		init_param(t_data *param);

#endif