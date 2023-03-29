/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:20:02 by jrenault          #+#    #+#             */
/*   Updated: 2023/01/17 15:05:45 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (param->map_tmp[y - 1][x] != '1')
		path_finding(param, x, y - 1);
	if (param->map_tmp[y][x + 1] != '1')
		path_finding(param, x + 1, y);
	if (param->map_tmp[y + 1][x] != '1')
		path_finding(param, x, y + 1);
	if (param->map_tmp[y][x - 1] != '1')
		path_finding(param, x - 1, y);
}
