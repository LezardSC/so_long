/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:39:02 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 15:21:11 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
	S = South = Front
	N = North = Back
	W = West = Left
	E = Est = Right
*/

int	draw_player(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (param->map[++y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'P')
			{
				if (param->player_direction == 'S')
					player_idle_animation_front(param, x, y);
				if (param->player_direction == 'N')
					player_idle_animation_back(param, x, y);
				if (param->player_direction == 'W')
					player_idle_animation_left(param, x, y);
				if (param->player_direction == 'E')
					player_idle_animation_right(param, x, y);
			}
			x++;
		}
		x = 0;
	}
	return (0);
}
