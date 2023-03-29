/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_corners.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:56:20 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/25 11:25:39 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_wall_semi_cross(t_data *param, int x, int y)
{
	if (x > 0 && y > 0 && x < param->max_x - 1
		&& param->map[y - 1][x] != '1' && param->map[y][x + 1] == '1'
		&& param->map[y][x - 1] == '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[7], x * 72, y * 72);
	else if (x > 0 && y > 0 && x < param->max_x - 1 && y < param->max_y - 1
		&& param->map[y][x + 1] == '1' && param->map[y + 1][x] == '1'
		&& param->map[y][x - 1] != '1' && param->map[y - 1][x] != '1'
		&& param->map[y + 1][x + 1] != '1')
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[21], x * 72, y * 72);
	else
		mlx_put_image_to_window(param->mlx, param->win,
			param->draw.wall_init[1], x * 72, y * 72);
}
