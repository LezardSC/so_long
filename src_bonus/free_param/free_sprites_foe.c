/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_foe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:04:23 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:46:49 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_sprites_foe(t_data *param)
{
	int	i;

	i = -1;
	while (++i <= 7)
		mlx_destroy_image(param->mlx, param->draw.foe_idle_front[i]);
	free(param->draw.foe_idle_front);
}
