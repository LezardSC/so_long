/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:52:55 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/25 13:53:51 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_items(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'C')
				mlx_put_image_to_window(param->mlx, param->win,
					param->draw.item_0, x * 72, y * 72);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_exit(t_data *param)
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
				draw_wall_up_left(param, x, y);
			else
				draw_ground(param, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	draw_all(t_data *param)
{
	if (draw_map(param) == 1)
		return (1);
	if (draw_items(param) == 1)
		return (1);
	if (param->end_game == 1)
		if (draw_exit(param) == 1)
			return (1);
	if (draw_player(param) == 1)
		return (1);
	if (draw_foe(param) == 1)
		return (1);
	return (0);
}
