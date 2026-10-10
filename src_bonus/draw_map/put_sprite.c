/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 12:00:00 by jrenault          #+#    #+#             */
/*   Updated: 2026/10/11 12:00:00 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static unsigned int	get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + y * img->line_len
		+ x * (img->bpp / 8)));
}

static void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	*(unsigned int *)(img->addr + y * img->line_len
			+ x * (img->bpp / 8)) = color;
}

static int	is_in_frame(t_img *frame, int x, int y)
{
	return (x >= 0 && y >= 0 && x < frame->width && y < frame->height);
}

void	put_sprite(t_data *param, t_img *sprite, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	if (!sprite || !param->draw.frame)
		return ;
	j = 0;
	while (j < sprite->height)
	{
		i = 0;
		while (i < sprite->width)
		{
			color = get_pixel(sprite, i, j);
			if ((color & 0xFF000000) == 0
				&& is_in_frame(param->draw.frame, x + i, y + j))
				set_pixel(param->draw.frame, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
