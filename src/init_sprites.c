/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:59 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/20 10:30:43 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sprites(t_data *param)
{
	int		img_width;
	int		img_height;

	param->draw.ground = mlx_xpm_file_to_image(param->mlx,
			"./graphics/tileset/ground_0.xpm", &img_width, &img_height);
	if (!param->draw.ground)
		return (1);
	param->draw.wall_center = mlx_xpm_file_to_image(param->mlx,
			"./graphics/tileset/wall_1.xpm", &img_width, &img_height);
	if (!param->draw.wall_center)
		return (1);
	param->draw.escape = mlx_xpm_file_to_image(param->mlx,
			"./graphics/escape/escape.xpm", &img_width, &img_height);
	if (!param->draw.escape)
		return (1);
	param->draw.item = mlx_xpm_file_to_image(param->mlx,
			"./graphics/items/item_0.xpm", &img_width, &img_height);
	if (!param->draw.item)
		return (1);
	init_player(param);
	return (0);
}

int	init_player(t_data *param)
{
	int		img_width;
	int		img_height;

	param->draw.player = mlx_xpm_file_to_image(param->mlx,
			"./graphics/player/player_walk_front_0.xpm",
			&img_width, &img_height);
	if (!param->draw.player)
		return (1);
	return (0);
}
