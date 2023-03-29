/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:59 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 08:07:24 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_sprites(t_data *param)
{
	if (init_sprites_map(param) == 1)
		return (1);
	if (init_sprites_player_foe(param) == 1)
		return (1);
	return (0);
}
