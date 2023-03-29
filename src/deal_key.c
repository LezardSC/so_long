/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:13:10 by jrenault          #+#    #+#             */
/*   Updated: 2023/01/20 16:22:51 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_data *param)
{
	if (key == 65307)
		close_win(param);
	if (key == 119)
		move_up(param);
	if (key == 97)
		move_left(param);
	if (key == 115)
		move_down(param);
	if (key == 100)
		move_right(param);
	return (0);
}
