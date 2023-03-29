/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ground.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:57:32 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 07:56:48 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_ground(t_data *param, int x, int y)
{
	mlx_put_image_to_window(param->mlx, param->win,
		param->draw.ground, x * 72, y * 72);
	return (0);
}
