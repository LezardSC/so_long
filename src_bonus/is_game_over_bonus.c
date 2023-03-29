/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:43:44 by jrenault          #+#    #+#             */
/*   Updated: 2023/01/20 16:52:58 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_game_over(t_data *param)
{
	int	x;
	int	y;
	int	c_count;

	x = 0;
	y = 0;
	c_count = 0;
	while (param->map[y])
	{
		while (param->map[y][x])
		{
			if (param->map[y][x] == 'C')
				c_count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (c_count);
}
