/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:34:15 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:21:22 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_data *param)
{
	mlx_destroy_window(param->mlx, param->win);
	free(param->map_name);
	free_all_param(param);
	free_init(param);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit (0);
}
