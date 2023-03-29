/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_foe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:13:54 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 16:51:16 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
	F = Foe

	S = South = Front
	N = North = Back
	W = West = Left
	E = Est = Right
*/

int	draw_foe(t_data *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'F')
				foe_idle_animation_front(param, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
