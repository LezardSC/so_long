/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:02:05 by jrenault          #+#    #+#             */
/*   Updated: 2023/03/20 08:39:39 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_argc(int argc)
{
	if (argc < 2)
		return (ft_printf("Error\nNo map given to the program."),
			1);
	if (argc > 2)
		return (ft_printf("Error\nToo many arguments."), 1);
	return (0);
}

static int	parsing_and_error(t_data *param, char *name)
{
	init_param(param);
	param->map_name = ft_strdup(name);
	if (!param->map_name)
		return (0);
	if (map_parsing(param, -1) == 1)
		return (free(param->map_name), free_all_param(param), 0);
	if (check_error(param) == 0)
		return (free(param->map_name), free_all_param(param), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	param;

	if (check_argc(argc) == 1)
		return (0);
	if (parsing_and_error(&param, argv[1]) == 0)
		return (0);
	param.mlx = mlx_init();
	if (!param.mlx)
		return (free(param.map_name), free_all_param(&param),
			mlx_destroy_display(param.mlx), free(param.mlx), 0);
	param.win = mlx_new_window(param.mlx,
			param.max_x * 72, param.max_y * 72, "so_long");
	if (!param.win)
		return (free(param.map_name), free_all_param(&param),
			mlx_destroy_display(param.mlx), free(param.mlx), 0);
	if (init_game(&param) == 1)
		return (free(param.map_name), free_all_param(&param), free_init(&param),
			mlx_destroy_display(param.mlx), free(param.mlx), 0);
	mlx_hook(param.win, 02, 1L << 0, deal_key, &param);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_loop(param.mlx);
	return (free(param.map_name), free_all_param(&param), free_init(&param),
		mlx_destroy_display(param.mlx), free(param.mlx), 0);
}
