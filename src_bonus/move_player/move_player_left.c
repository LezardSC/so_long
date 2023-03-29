/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:14:00 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 14:18:27 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_left(t_data *param)
{
	if (param->map[param->p_y][param->p_x - 1] != '1')
	{
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = '0';
		param->p_x--;
		if (param->map[param->p_y][param->p_x] == 'F')
			close_win(param);
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = 'P';
		if (draw_all(param))
			return (1);
		if (param->map[param->p_y][param->p_x] == 'E' && param->end_game == 1)
			close_win(param);
		else if (param->map[param->p_y][param->p_x] == 'E')
		{
			param->e_x = param->p_x;
			param->e_y = param->p_y;
			param->map[param->p_y][param->p_x] = 'P';
			draw_player(param);
		}
		param->move_count++;
	}
	return (0);
}
