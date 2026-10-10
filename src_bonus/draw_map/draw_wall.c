/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:27:22 by jrenault          #+#    #+#             */
/*   Updated: 2026/10/11 12:00:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
	masks[i] = neighbours drawn by wall_i.xpm (out of map counts as wall).
	N = 1, E = 2, S = 4, W = 8, NE = 16, SE = 32, SW = 64, NW = 128.
	A diagonal only counts when both of its sides are walls.
*/

static int	is_wall(t_data *param, int x, int y)
{
	if (x < 0 || y < 0 || x >= param->max_x || y >= param->max_y)
		return (1);
	return (param->map[y][x] == '1');
}

static int	get_wall_mask(t_data *param, int x, int y)
{
	int	mask;

	mask = is_wall(param, x, y - 1) | (is_wall(param, x + 1, y) << 1)
		| (is_wall(param, x, y + 1) << 2) | (is_wall(param, x - 1, y) << 3);
	if ((mask & 3) == 3 && is_wall(param, x + 1, y - 1))
		mask |= 16;
	if ((mask & 6) == 6 && is_wall(param, x + 1, y + 1))
		mask |= 32;
	if ((mask & 12) == 12 && is_wall(param, x - 1, y + 1))
		mask |= 64;
	if ((mask & 9) == 9 && is_wall(param, x - 1, y - 1))
		mask |= 128;
	return (mask);
}

static int	find_wall_tile(int mask)
{
	static const int	masks[41] = {0, 255, 155, 19, 205, 55, 137, 110, 38,
		76, 239, 127, 223, 191, 15, 1, 2, 8, 4, 5, 10, 6, 159, 14, 63, 23,
		141, 13, 77, 11, 7, 111, 207, 9, 12, 3, 46, 139, 78, 27, 39};
	int					i;

	i = 0;
	while (i < 41 && masks[i] != mask)
		i++;
	if (i < 41)
		return (i);
	return (find_wall_tile(mask & 15));
}

void	draw_wall(t_data *param, int x, int y)
{
	put_sprite(param, param->draw.wall_init[find_wall_tile(
			get_wall_mask(param, x, y))], x * 72, y * 72);
}
