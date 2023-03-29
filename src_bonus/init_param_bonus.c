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
	param->foe_idle_front_frame = 0;
	param->player_idle_front_frame = 0;
	param->player_idle_back_frame = 0;
	param->player_idle_left_frame = 0;
	param->player_idle_right_frame = 0;
	param->end_game = 0;
	param->e_x = 0;
	param->e_y = 0;
	return (0);
}
