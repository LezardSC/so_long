/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:00:00 by jrenault          #+#    #+#             */
/*   Updated: 2026/10/11 12:00:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_held(t_data *param, char direction)
{
	return ((direction == 'N' && param->key_up)
		|| (direction == 'S' && param->key_down)
		|| (direction == 'W' && param->key_left)
		|| (direction == 'E' && param->key_right));
}

static int	turn_to_held_key(t_data *param, long long now)
{
	if (param->key_up)
		param->player_direction = 'N';
	else if (param->key_down)
		param->player_direction = 'S';
	else if (param->key_left)
		param->player_direction = 'W';
	else if (param->key_right)
		param->player_direction = 'E';
	else
		return (0);
	param->last_move_mtimestamp = now;
	return (0);
}

int	move_player(t_data *param)
{
	long long	now;

	now = millitimestamp();
	if (now - param->last_move_mtimestamp < MOVE_DELAY)
		return (0);
	if (!is_held(param, param->player_direction))
		return (turn_to_held_key(param, now));
	param->last_move_mtimestamp = now;
	if (param->player_direction == 'N')
		return (move_up(param));
	if (param->player_direction == 'S')
		return (move_down(param));
	if (param->player_direction == 'W')
		return (move_left(param));
	return (move_right(param));
}
