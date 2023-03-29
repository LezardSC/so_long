/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_error_bis.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jrenault <jrenault@student.42lyon.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/12 13:58:22 by jrenault		  #+#	#+#			 */
/*   Updated: 2023/01/14 17:20:18 by jrenault		 ###   ########lyon.fr   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_data *param)
{
	int		i;

	i = 0;
	param->map_tmp = malloc(sizeof(char *) * (param->max_y + 1));
	if (param->map_tmp == NULL)
	{
		free(param->map_name);
		free_all_param(param);
		ft_printf("Malloc error.\n");
		exit(0);
	}
	while (i < param->max_y)
	{
		param->map_tmp[i] = malloc(sizeof(char *) * (param->max_x));
		if (param->map_tmp[i] == NULL)
		{
			free(param->map_name);
			free_all_param(param);
			ft_printf("Malloc error.\n");
			exit(0);
		}
		ft_strcpy(param->map_tmp[i], param->map[i]);
		i++;
	}
	param->map_tmp[i] = NULL;
}

int	check_path(t_data *param)
{
	int		p_x;
	int		p_y;

	p_x = 0;
	p_y = 0;
	copy_map(param);
	while (param->map_tmp[p_y])
	{
		while (param->map_tmp[p_y][p_x])
		{
			if (param->map_tmp[p_y][p_x] == 'P')
				break ;
			p_x++;
		}
		if (param->map_tmp[p_y][p_x] == 'P')
			break ;
		p_x = 0;
		p_y++;
	}
	param->nb_c_tmp = param->nb_collectible;
	param->nb_e_tmp = 1;
	path_finding(param, p_x, p_y);
	if (param->nb_c_tmp == 0 && param->nb_e_tmp == 0)
		return (param->p_x = p_x, param->p_y = p_y, 0);
	return (1);
}
