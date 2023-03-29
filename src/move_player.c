/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:15:08 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 07:45:45 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *param)
{
	int	end_game;

	end_game = 0;
	if (is_game_over(param) == 0)
		end_game = 1;
	if (param->map[param->p_y - 1][param->p_x] != '1')
	{
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = '0';
		param->p_y--;
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = 'P';
		if (draw_all(param))
			return (1);
		if (param->map[param->p_y][param->p_x] == 'E' && end_game == 1)
			close_win(param);
		else if (param->map[param->p_y][param->p_x] == 'E')
			mlx_put_image_to_window(param->mlx, param->win,
				param->draw.player,
				param->p_x * 72, param->p_y * 72);
		param->move_count++;
		ft_printf("number of movements: %d\n", param->move_count);
	}
	return (0);
}

int	move_left(t_data *param)
{
	int	end_game;

	end_game = 0;
	if (is_game_over(param) == 0)
		end_game = 1;
	if (param->map[param->p_y][param->p_x - 1] != '1')
	{
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = '0';
		param->p_x--;
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = 'P';
		if (draw_all(param))
			return (1);
		if (param->map[param->p_y][param->p_x] == 'E' && end_game == 1)
			close_win(param);
		else if (param->map[param->p_y][param->p_x] == 'E')
			mlx_put_image_to_window(param->mlx, param->win,
				param->draw.player,
				param->p_x * 72, param->p_y * 72);
		param->move_count++;
		ft_printf("number of movements: %d\n", param->move_count);
	}
	return (0);
}

int	move_down(t_data *param)
{
	int	end_game;

	end_game = 0;
	if (is_game_over(param) == 0)
		end_game = 1;
	if (param->map[param->p_y + 1][param->p_x] != '1')
	{
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = '0';
		param->p_y++;
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = 'P';
		if (draw_all(param))
			return (1);
		if (param->map[param->p_y][param->p_x] == 'E' && end_game == 1)
			close_win(param);
		else if (param->map[param->p_y][param->p_x] == 'E')
			mlx_put_image_to_window(param->mlx, param->win,
				param->draw.player,
				param->p_x * 72, param->p_y * 72);
		param->move_count++;
		ft_printf("number of movements: %d\n", param->move_count);
	}
	return (0);
}

int	move_right(t_data *param)
{
	int	end_game;

	end_game = 0;
	if (is_game_over(param) == 0)
		end_game = 1;
	if (param->map[param->p_y][param->p_x + 1] != '1')
	{
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = '0';
		param->p_x++;
		if (param->map[param->p_y][param->p_x] != 'E')
			param->map[param->p_y][param->p_x] = 'P';
		if (draw_all(param))
			return (1);
		if (param->map[param->p_y][param->p_x] == 'E' && end_game == 1)
			close_win(param);
		else if (param->map[param->p_y][param->p_x] == 'E')
			mlx_put_image_to_window(param->mlx, param->win,
				param->draw.player,
				param->p_x * 72, param->p_y * 72);
		param->move_count++;
		ft_printf("number of movements: %d\n", param->move_count);
	}
	return (0);
}
