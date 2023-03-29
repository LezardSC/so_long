/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_idle_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:02:43 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 15:04:28 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	foe_idle_animation_front(t_data *param, int x, int y)
{
	if (param->animation_frame % 10 == 0)
		param->foe_idle_front_frame++;
	mlx_put_image_to_window(param->mlx, param->win,
		param->draw.foe_idle_front[param->foe_idle_front_frame],
		x * 72, y * 72);
	if (param->foe_idle_front_frame == 7)
		param->foe_idle_front_frame = 0;
	return (0);
}
