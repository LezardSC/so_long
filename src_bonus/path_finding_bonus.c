/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:20:02 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:02:10 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_backtrack(t_data *param, int x, int y)
{
	if (param->map_tmp[y][x] == 'C')
		param->nb_c_tmp--;
	if (param->map_tmp[y][x] == 'E')
		param->nb_e_tmp--;
	param->map_tmp[y][x] = '1';
}

void	path_finding(t_data *param, int x, int y)
{
	update_backtrack(param, x, y);
	if (param->map_tmp[y - 1][x] != '1' && param->map_tmp[y - 1][x] != 'F')
		path_finding(param, x, y - 1);
	if (param->map_tmp[y][x + 1] != '1' && param->map_tmp[y][x + 1] != 'F')
		path_finding(param, x + 1, y);
	if (param->map_tmp[y + 1][x] != '1' && param->map_tmp[y + 1][x] != 'F')
		path_finding(param, x, y + 1);
	if (param->map_tmp[y][x - 1] != '1' && param->map_tmp[y][x - 1] != 'F')
		path_finding(param, x - 1, y);
}
