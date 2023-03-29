/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:11:44 by jrenault          #+#    #+#             */
/*   Updated: 2023/01/28 17:44:57 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_param(t_data *param)
{
	param->nb_collectible = 0;
	param->move_count = 0;
	param->map = NULL;
	param->map_tmp = NULL;
	return (0);
}
