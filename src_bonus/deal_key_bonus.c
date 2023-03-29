/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:13:10 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 16:52:58 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	deal_key_move_front(t_data *param)
{
	if (param->player_direction == 'N')
		move_up(param);
	else
		param->player_direction = 'N';
	return (0);
}

int	deal_key_move_back(t_data *param)
{
	if (param->player_direction == 'S')
		move_down(param);
	else
		param->player_direction = 'S';
	return (0);
}

int	deal_key_move_left(t_data *param)
{
	if (param->player_direction == 'W')
		move_left(param);
	else
		param->player_direction = 'W';
	return (0);
}

int	deal_key_move_right(t_data *param)
{
	if (param->player_direction == 'E')
		move_right(param);
	else
		param->player_direction = 'E';
	return (0);
}

int	deal_key(int key, t_data *param)
{
	if (key == 65307)
		close_win(param);
	if (key == 119)
		deal_key_move_front(param);
	if (key == 97)
	{
		deal_key_move_left(param);
	}
	if (key == 115)
	{
		deal_key_move_back(param);
	}
	if (key == 100)
	{
		deal_key_move_right(param);
	}
	return (0);
}
