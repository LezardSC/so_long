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

int	init_sprites_map(t_data *param)
{
	param->draw.ground = load_sprite(param, "./graphics/tileset/ground_0.xpm");
	if (!param->draw.ground)
		return (1);
	param->draw.wall_init = init_imgs(param, "./graphics/tileset/wall_", 41, 0);
	if (!param->draw.wall_init)
		return (1);
	param->draw.escape = load_sprite(param, "./graphics/escape/escape.xpm");
	if (!param->draw.escape)
		return (1);
	param->draw.item_0 = load_sprite(param, "./graphics/items/item_0.xpm");
	if (!param->draw.item_0)
		return (1);
	return (0);
}
