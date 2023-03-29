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
	int	i;

	i = -1;
	while (++i <= 3)
	{
		if (param->draw.player_idle_left[i])
			mlx_destroy_image(param->mlx, param->draw.player_idle_left[i]);
	}
	free(param->draw.player_idle_left);
	i = -1;
	while (++i <= 3)
	{
		if (param->draw.player_idle_right[i])
			mlx_destroy_image(param->mlx, param->draw.player_idle_right[i]);
	}
	free(param->draw.player_idle_right);
}

void	free_sprites_player(t_data *param)
{
	int	i;

	i = -1;
	while (++i <= 3)
	{
		if (param->draw.player_idle_front[i])
			mlx_destroy_image(param->mlx, param->draw.player_idle_front[i]);
	}
	free(param->draw.player_idle_front);
	i = -1;
	while (++i <= 3)
	{
		if (param->draw.player_idle_back[i])
			mlx_destroy_image(param->mlx, param->draw.player_idle_back[i]);
	}
	free(param->draw.player_idle_back);
	free_sprites_player_2(param);
}
