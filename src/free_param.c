/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:55:27 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:21:03 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all_param(t_data *param)
{
	int	i;

	i = 0;
	if (param->map)
	{
		while (param->map && param->map[i])
		{
			free(param->map[i]);
			i++;
		}
		free(param->map);
	}
	if (param->map_tmp)
	{
		i = 0;
		while (param->map_tmp && param->map_tmp[i])
		{
			free(param->map_tmp[i]);
			i++;
		}
		free(param->map_tmp);
	}
	return (0);
}

int	free_init(t_data *param)
{
	mlx_destroy_image(param->mlx, param->draw.ground);
	mlx_destroy_image(param->mlx, param->draw.escape);
	mlx_destroy_image(param->mlx, param->draw.item);
	mlx_destroy_image(param->mlx, param->draw.player);
	mlx_destroy_image(param->mlx, param->draw.wall_center);
	return (0);
}
