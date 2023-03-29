/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:01:34 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/14 08:32:05 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Get timestamp in milliseconds
long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

// Show FPS in the window
void	show_fps(t_data *param)
{
	char	*put_fps;
	char	*fps;

	fps = ft_itoa(param->fps);
	put_fps = ft_strjoin("FPS: ", fps);
	mlx_string_put(param->mlx, param->win, 20, 30, 00000000, put_fps);
	free(fps);
	free(put_fps);
}

// Calculate FPS
void	ft_fps(t_data *param)
{
	long long	now;

	now = millitimestamp();
	if (now > param->last_mtimestamp)
	{
		param->fps = 960 / (now - param->last_mtimestamp);
		param->animation_frame++;
		param->last_mtimestamp = now;
	}
}
