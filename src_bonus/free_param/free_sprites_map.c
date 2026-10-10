/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:10:58 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:45:35 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_sprites_map(t_data *param)
{
	destroy_sprite(param, param->draw.ground);
	free_imgs(param, param->draw.wall_init);
	destroy_sprite(param, param->draw.escape);
	destroy_sprite(param, param->draw.item_0);
}
