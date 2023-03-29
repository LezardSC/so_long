/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:59:37 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/29 17:13:42 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_parsing(int num_error)
{
	if (num_error == 1)
	{
		ft_printf("Error\nCouldn't open the map.");
	}
	if (num_error == 2)
	{
		ft_printf("Error\nThe map is not a valid '.ber'.");
	}
	if (num_error == 3)
	{
		ft_printf("Error\nThe map is empty.");
	}
	if (num_error == 4)
	{
		ft_printf("Error\nget_next_line error.");
	}
	return (0);
}

int	is_name_correct(t_data *param)
{
	int	size;

	size = ft_strlen(param->map_name);
	if (size >= 5 && param->map_name[size - 1] == 'r'
		&& param->map_name[size - 2] == 'e' && param->map_name[size - 3] == 'b'
		&& param->map_name[size - 4] == '.')
		return (0);
	error_parsing(2);
	return (1);
}

static int	number_of_line(t_data *param)
{
	int		fd;
	int		n;
	char	*buf;

	n = 0;
	if (is_name_correct(param) == 1)
	{
		return (-1);
	}
	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
	{
		error_parsing(1);
		return (-1);
	}
	buf = get_next_line(fd);
	if (!buf)
		return (close(fd), -2);
	while (buf)
	{
		n++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (close(fd), n);
}

int	map_parsing(t_data *param, int i)
{
	int		fd;

	param->max_y = number_of_line(param);
	if (param->max_y == -1)
		return (1);
	if (param->max_y == -2)
		return (4);
	if (param->max_y == 0)
		return (error_parsing(3), 1);
	param->map = malloc(sizeof(char *) * (param->max_y + 1));
	if (param->map == NULL)
		return (1);
	fd = open(param->map_name, O_RDONLY);
	if (fd == -1)
		return (error_parsing(1), close(fd), 1);
	while (++i < param->max_y)
	{
		param->map[i] = get_next_line(fd);
		if (param->map[i][ft_strlen(param->map[i]) - 1] == '\n')
			param->map[i][ft_strlen(param->map[i]) - 1] = '\0';
	}
	param->max_x = ft_strlen(param->map[0]);
	return (param->map[i] = NULL, close(fd), 0);
}
