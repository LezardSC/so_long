/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:52:55 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 07:44:54 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_player(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'P')
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.player, x * 72, y * 72);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_items_exit(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'E')
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.escape, x * 72, y * 72);
			if (param->map[y][x] == 'C')
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.item, x * 72, y * 72);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_map(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == '1')
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.wall_center, x * 72, y * 72);
			else
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.ground, x * 72, y * 72);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_all(t_data *param)
{
	if (draw_map(param))
		return (1);
	if (draw_items_exit(param))
		return (1);
	if (draw_player(param))
		return (1);
	return (0);
}
