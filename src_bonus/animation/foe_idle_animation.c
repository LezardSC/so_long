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
	put_sprite(param,
		param->draw.foe_idle_front[param->foe_idle_frame],
		x * 72, y * 72);
	return (0);
}
