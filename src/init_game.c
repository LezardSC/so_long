/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:39:34 by jrenault          #+#    #+#             */
/*   Updated: 2023/01/28 17:12:36 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_data *param)
{
	if (init_sprites(param) == 1)
		return (1);
	if (draw_map(param) == 1)
		return (1);
	if (draw_items_exit(param) == 1)
		return (1);
	if (draw_player(param) == 1)
		return (1);
	return (0);
}
