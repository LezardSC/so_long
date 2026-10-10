/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:11:44 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 17:10:49 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_param(t_data *param)
{
	param->nb_collectible = 0;
	param->move_count = 0;
	param->last_mtimestamp = 0;
	param->map = NULL;
	param->map_tmp = NULL;
	param->player_direction = 'S';
	param->animation_frame = 0;
	param->foe_idle_frame = 0;
	param->player_idle_frame = 0;
	param->end_game = 0;
	param->key_up = 0;
	param->key_down = 0;
	param->key_left = 0;
	param->key_right = 0;
	param->last_move_mtimestamp = 0;
	param->e_x = 0;
	param->e_y = 0;
	ft_bzero(&param->draw, sizeof(t_draw));
	return (0);
}
