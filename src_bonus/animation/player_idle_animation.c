/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_idle_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:40:34 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 17:00:51 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	player_idle_animation_back(t_data *param, int x, int y)
{
	put_sprite(param,
		param->draw.player_idle_back[param->player_idle_frame],
		x * 72, y * 72);
	return (0);
}

int	player_idle_animation_left(t_data *param, int x, int y)
{
	put_sprite(param,
		param->draw.player_idle_left[param->player_idle_frame],
		x * 72, y * 72);
	return (0);
}

int	player_idle_animation_right(t_data *param, int x, int y)
{
	put_sprite(param,
		param->draw.player_idle_right[param->player_idle_frame],
		x * 72, y * 72);
	return (0);
}

int	player_idle_animation_front(t_data *param, int x, int y)
{
	put_sprite(param,
		param->draw.player_idle_front[param->player_idle_frame],
		x * 72, y * 72);
	return (0);
}
