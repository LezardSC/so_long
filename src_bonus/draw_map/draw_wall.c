/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:27:22 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/25 11:24:23 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_wall_up_left(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y - 1][x] != '1' && param->map[y + 1][x] != '1'
		&& param->map[y][x - 1] != '1' && param->map[y][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[0], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y + 1][x + 1] != '1' && param->map[y + 1][x - 1] != '1'
		&& param->map[y - 1][x + 1] != '1' && param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[14], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y + 1][x] != '1' && param->map[y - 1][x] == '1'
		&& param->map[y + 1][x + 1] != '1' && param->map[y + 1][x - 1] != '1'
		&& param->map[y - 1][x + 1] != '1' && param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[29], x * 72, y * 72);
	else
		draw_wall_up_right(param, x, y);
}

void	draw_wall_up_right(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] != '1'
		&& param->map[y + 1][x + 1] != '1' && param->map[y + 1][x - 1] != '1'
		&& param->map[y - 1][x + 1] != '1' && param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[23], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] != '1' && param->map[y][x - 1] == '1'
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y + 1][x - 1] != '1' && param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[27], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y + 1][x + 1] != '1' && param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[30], x * 72, y * 72);
	else
		draw_wall_down_left(param, x, y);
}

void	draw_wall_down_left(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x + 1] != '1' && param->map[y - 1][x] != '1'
		&& param->map[y + 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[34], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y][x - 1] != '1' && param->map[y + 1][x] != '1'
		&& param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[35], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y][x + 1] != '1' && param->map[y + 1][x] != '1'
		&& param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[33], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] != '1' && param->map[y][x - 1] == '1'
		&& param->map[y - 1][x] == '1' && param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[28], x * 72, y * 72);
	else
		draw_wall_down_right(param, x, y);
}

void	draw_wall_down_right(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y - 1][x] == '1' && param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[40], x * 72, y * 72);
	else if (y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] != '1'
		&& param->map[y][x + 1] == '1' && param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[38], x * 72, y * 72);
	else if (y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y - 1][x] == '1' && param->map[y + 1][x] != '1'
		&& param->map[y][x + 1] == '1' && param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[37], x * 72, y * 72);
	else if (x > 0 && y > 0 && y < param->max_y - 1
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] != '1'
		&& param->map[y][x - 1] == '1' && param->map[y + 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[36], x * 72, y * 72);
	else
		draw_wall_left(param, x, y);
}

void	draw_wall_left(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && y < param->max_y - 1
		&& param->map[y - 1][x] == '1' && param->map[y + 1][x] != '1'
		&& param->map[y][x - 1] == '1' && param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[39], x * 72, y * 72);
	else if (x > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y][x + 1] != '1'
		&& param->map[y + 1][x] == '1' && param->map[y + 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[26], x * 72, y * 72);
	else if (x > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y + 1][x] == '1' && param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[25], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y - 1][x] == '1' && param->map[y - 1][x - 1] != '1'
		&& param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[31], x * 72, y * 72);
	else
		draw_wall_right(param, x, y);
}
