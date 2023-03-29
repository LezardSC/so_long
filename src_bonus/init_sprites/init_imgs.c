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

void	**init_imgs(t_data *param, const char *img_path, int nb_imgs, int n)
{
	int		img_width;
	int		img_height;
	char	*char_n;
	char	*path;
	void	**imgs;

	imgs = malloc(sizeof(void *) * nb_imgs + 1);
	while (n < nb_imgs && imgs != NULL)
	{
		char_n = ft_itoa(n);
		path = join_path_name(img_path, char_n);
		if (path != NULL)
			imgs[n] = mlx_xpm_file_to_image(param->mlx,
					path, &img_width, &img_height);
		n++;
		free(char_n);
		free(path);
	}
	return (imgs);
}
