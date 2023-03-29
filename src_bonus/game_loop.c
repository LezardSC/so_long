/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:21:27 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 17:08:59 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

int	game_loop(t_data *param)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = (now - param->last_mtimestamp);
	if (param->animation_frame == 20)
		param->animation_frame = 0;
	if (diff_millisecs > 45)
	{
		if (is_game_over(param) == 0)
			param->end_game = 1;
		if (param->end_game == 1 && param->e_y > 0 && param->e_x > 0)
			param->map[param->e_y][param->e_x] = 'E';
		param->animation_frame++;
		ft_fps(param);
		draw_all(param);
		show_fps(param);
		show_move(param);
	}
	return (0);
}
