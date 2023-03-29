/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:46 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/29 16:43:22 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wrong_letters(t_data *param)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (param->map[++i])
	{
		while (param->map[i][++j])
		{
			if (param->map[i][j] != 'C' && param->map[i][j] != 'P' &&
				param->map[i][j] != 'E' && param->map[i][j] != '0' &&
				param->map[i][j] != '1')
			{
				return (1);
			}
		}
		j = -1;
	}
	return (0);
}

int	check_factors(t_data *param, int i, int j)
{
	int	nb_exit;
	int	nb_player;

	nb_exit = 0;
	nb_player = 0;
	while (param->map[++i])
	{
		while (param->map[i][++j])
		{
			if (param->map[i][j] == 'C')
			{
				param->nb_collectible++;
			}
			else if (param->map[i][j] == 'E')
				nb_exit++;
			else if (param->map[i][j] == 'P')
				nb_player++;
		}
		j = -1;
	}
	if (nb_exit != 1 || nb_player != 1 || param->nb_collectible == 0)
		return (1);
	return (0);
}

int	check_walls(t_data *param)
{
	int	i;

	i = 0;
	while (param->map[0] && param->map[0][i])
	{
		if (param->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (param->map[param->max_y - 1] && param->map[param->max_y - 1][i])
	{
		if (param->map[param->max_y - 1][i++] != '1')
			return (1);
	}
	i = 0;
	while (param->map[i])
	{
		if (param->map[i][0] != '1')
			return (1);
		if (param->map[i][param->max_x - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_data *param)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!param->map || !param->map[0])
		return (5);
	size = ft_strlen(param->map[0]);
	while (param->map[i])
	{
		if (size != ft_strlen(param->map[i]))
			return (1);
		i++;
	}
	if (check_walls(param) == 1)
		return (2);
	if (check_factors(param, -1, -1) == 1)
		return (3);
	if (check_wrong_letters(param) == 1)
		return (4);
	if (check_path(param) == 1)
		return (5);
	return (0);
}

int	check_error(t_data *param)
{
	int	error;

	error = check_map(param);
	if (error == 1)
	{
		ft_printf("Error\nThe map isn't a rectangle.");
		return (0);
	}
	else if (error == 2)
	{
		ft_printf("Error\nThe map has no bordure.");
		return (0);
	}
	else if (error == 3)
	{
		ft_printf("Error\nThe map have not the right amount of factors.");
		return (0);
	}
	else if (error == 4)
		return (ft_printf("Error\nWrong letters in map."), 0);
	else if (error == 5)
		return (ft_printf("Error\nThe level cannot be completed."), 0);
	return (1);
}
