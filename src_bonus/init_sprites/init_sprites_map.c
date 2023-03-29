/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:05:42 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 14:08:17 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
	The order for the walls is:
	0 - wall_alone	/	1 - wall_center
	2 - wall_down	/	3 - wall_downleft
	4 - wall_downright /5 - wall_left
	6 - wall_right	/	7 - wall_up
	8 - wall_upleft	/	8 - wall_upright
*/

int	init_sprites_map(t_data *param)
{
	int	img_width;
	int	img_height;

	param->draw.ground = mlx_xpm_file_to_image(param->mlx,
			"./graphics/tileset/ground_0.xpm", &img_width, &img_height);
	if (!param->draw.ground)
		return (1);
	param->draw.wall_init = init_imgs(param, "./graphics/tileset/wall_", 41, 0);
	if (!param->draw.wall_init)
		return (1);
	param->draw.escape = mlx_xpm_file_to_image(param->mlx,
			"./graphics/escape/escape.xpm", &img_width, &img_height);
	if (!param->draw.escape)
		return (1);
	param->draw.item_0 = mlx_xpm_file_to_image(param->mlx,
			"./graphics/items/item_0.xpm", &img_width, &img_height);
	if (!param->draw.item_0)
		return (1);
	return (0);
}
