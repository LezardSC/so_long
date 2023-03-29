/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_player_foe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:09:45 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/19 16:21:26 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_sprites_player_foe(t_data *param)
{
	param->draw.player_idle_front = init_imgs(param,
			"./graphics/player/player_walk_front_", 4, 0);
	if (!param->draw.player_idle_front)
		return (1);
	param->draw.player_idle_back = init_imgs(param,
			"./graphics/player/player_walk_back_", 4, 0);
	if (!param->draw.player_idle_back)
		return (1);
	param->draw.player_idle_left = init_imgs(param,
			"./graphics/player/player_walk_left_", 4, 0);
	if (!param->draw.player_idle_left)
		return (1);
	param->draw.player_idle_right = init_imgs(param,
			"./graphics/player/player_walk_right_", 4, 0);
	if (!param->draw.player_idle_right)
		return (1);
	param->draw.foe_idle_front = init_imgs(param,
			"./graphics/foe/foe_idle_front_", 8, 0);
	if (!param->draw.foe_idle_front)
		return (1);
	return (0);
}
