/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:17:14 by jrenault          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:06 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*join_path_name(const char *img_path, char *char_n)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(img_path, char_n);
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	return (path);
}

t_img	**init_imgs(t_data *param, const char *img_path, int nb_imgs, int n)
{
	char	*char_n;
	char	*path;
	t_img	**imgs;

	imgs = ft_calloc(nb_imgs + 1, sizeof(t_img *));
	while (n < nb_imgs && imgs != NULL)
	{
		char_n = ft_itoa(n);
		path = join_path_name(img_path, char_n);
		if (path != NULL)
			imgs[n] = load_sprite(param, path);
		free(char_n);
		free(path);
		if (imgs[n] == NULL)
			return (free_imgs(param, imgs), NULL);
		n++;
	}
	return (imgs);
}
