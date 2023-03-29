/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:00:34 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/15 15:08:05 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	show_move(t_data *param)
{
	char	*move_count;
	char	*move_string;

	move_count = ft_itoa(param->move_count);
	move_string = ft_strjoin("Move: ", move_count);
	mlx_string_put(param->mlx, param->win, 20, 50, 00000000, move_string);
	free(move_count);
	free(move_string);
	return (0);
}
