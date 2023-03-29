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
	int	i;

	mlx_destroy_image(param->mlx, param->draw.ground);
	i = 0;
	while (i <= 40)
	{
		if (param->draw.wall_init[i])
			mlx_destroy_image(param->mlx, param->draw.wall_init[i]);
		i++;
	}
	free(param->draw.wall_init);
	mlx_destroy_image(param->mlx, param->draw.escape);
	mlx_destroy_image(param->mlx, param->draw.item_0);
}
