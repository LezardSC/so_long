/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_center.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:55:26 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/25 11:25:27 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_wall_right(t_data *param, int x, int y)
{
	if (y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y - 1][x] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x + 1] == '1' && param->map[y - 1][x + 1] != '1'
		&& param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[32], x * 72, y * 72);
	else if (x > 0 && y > 0 && y < param->max_y - 1
		&& param->map[y - 1][x] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x - 1] == '1' && param->map[y - 1][x - 1] != '1'
		&& param->map[y + 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[24], x * 72, y * 72);
	else if (x > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y + 1][x] == '1' && param->map[y + 1][x - 1] != '1'
		&& param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[22], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y + 1][x] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y][x + 1] != '1' && param->map[y - 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[18], x * 72, y * 72);
	else
		draw_wall_up(param, x, y);
}

void	draw_wall_up(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y - 1][x] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y][x + 1] != '1' && param->map[y + 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[15], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] != '1'
		&& param->map[y + 1][x] != '1' && param->map[y - 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[16], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y][x + 1] != '1'
		&& param->map[y + 1][x] != '1' && param->map[y - 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[17], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y][x - 1] == '1'
		&& param->map[y - 1][x] != '1' && param->map[y + 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[20], x * 72, y * 72);
	else
		draw_wall_down(param, x, y);
}

void	draw_wall_down(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y + 1][x] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y][x + 1] != '1' && param->map[y][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[19], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x - 1] != '1' && param->map[y - 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[8], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x + 1] != '1' && param->map[y - 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[9], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y][x - 1] != '1' && param->map[y + 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[3], x * 72, y * 72);
	else
		draw_wall_center(param, x, y);
}

void	draw_wall_center(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y][x + 1] != '1' && param->map[y + 1][x] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[6], x * 72, y * 72);
	else if (x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[12], x * 72, y * 72);
	else if (x > 0 && y < param->max_y - 1
		&& param->map[y][x - 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y + 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[13], x * 72, y * 72);
	else if (y > 0 && x < param->max_x - 1
		&& param->map[y][x + 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y - 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[10], x * 72, y * 72);
	else
		draw_wall_cross(param, x, y);
}

void	draw_wall_cross(t_data *param, int x, int y)
{
	if (x > 0 && y > 0
		&& param->map[y][x - 1] == '1' && param->map[y - 1][x] == '1'
		&& param->map[y - 1][x - 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[11], x * 72, y * 72);
	else if (x > 0 && y > 0 && y < param->max_y - 1
		&& param->map[y][x - 1] != '1' && param->map[y + 1][x] == '1'
		&& param->map[y - 1][x] == '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[5], x * 72, y * 72);
	else if (y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] != '1' && param->map[y + 1][x] == '1'
		&& param->map[y - 1][x] == '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[4], x * 72, y * 72);
	else if (x > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y + 1][x] != '1' && param->map[y][x + 1] == '1'
		&& param->map[y][x - 1] == '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[2], x * 72, y * 72);
	else
		draw_wall_semi_cross(param, x, y);
}
