/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:13:10 by jrenault          #+#    #+#             */
/*   Updated: 2026/10/11 12:00:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	press_direction(t_data *param, int *key, char direction)
{
	*key = 1;
	if (param->player_direction != direction)
	{
		param->player_direction = direction;
		param->last_move_mtimestamp = millitimestamp();
	}
	else
		move_player(param);
}

int	deal_key(int key, t_data *param)
{
	if (key == 65307)
		close_win(param);
	if (key == 119)
		press_direction(param, &param->key_up, 'N');
	if (key == 97)
		press_direction(param, &param->key_left, 'W');
	if (key == 115)
		press_direction(param, &param->key_down, 'S');
	if (key == 100)
		press_direction(param, &param->key_right, 'E');
	return (0);
}

int	deal_key_release(int key, t_data *param)
{
	if (key == 119)
		param->key_up = 0;
	if (key == 97)
		param->key_left = 0;
	if (key == 115)
		param->key_down = 0;
	if (key == 100)
		param->key_right = 0;
	return (0);
}
