/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:00:00 by jrenault          #+#    #+#             */
/*   Updated: 2026/10/11 12:00:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	*load_sprite(t_data *param, char *path)
{
	t_img	*sprite;

	sprite = malloc(sizeof(t_img));
	if (!sprite)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(param->mlx, path,
			&sprite->width, &sprite->height);
	if (!sprite->img)
		return (free(sprite), NULL);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
	return (sprite);
}

t_img	*create_frame(t_data *param, int width, int height)
{
	t_img	*frame;

	frame = malloc(sizeof(t_img));
	if (!frame)
		return (NULL);
	frame->img = mlx_new_image(param->mlx, width, height);
	if (!frame->img)
		return (free(frame), NULL);
	frame->width = width;
	frame->height = height;
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->line_len, &frame->endian);
	return (frame);
}

void	destroy_sprite(t_data *param, t_img *sprite)
{
	if (!sprite)
		return ;
	mlx_destroy_image(param->mlx, sprite->img);
	free(sprite);
}

void	free_imgs(t_data *param, t_img **imgs)
{
	int	i;

	if (!imgs)
		return ;
	i = 0;
	while (imgs[i])
	{
		destroy_sprite(param, imgs[i]);
		i++;
	}
	free(imgs);
}
