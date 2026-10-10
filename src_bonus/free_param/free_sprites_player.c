/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:04:10 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:46:31 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_sprites_player_2(t_data *param)
{
	free_imgs(param, param->draw.player_idle_left);
	free_imgs(param, param->draw.player_idle_right);
}

void	free_sprites_player(t_data *param)
{
	free_imgs(param, param->draw.player_idle_front);
	free_imgs(param, param->draw.player_idle_back);
	free_sprites_player_2(param);
}
