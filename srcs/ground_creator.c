/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:52:54 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/29 14:30:50 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ground_creator(t_data *data)
{
	char *path_ground;
	int x;
	int y;
	int img_width;
	int img_heigth;

	x = 0;
	y = 0;
	path_ground = "./assets/grass2.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_ground, &img_width, &img_heigth);
	if (!data->img)
	{
		ft_printf("error\n");
		return ;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
			x += img_width;
		}
		y += img_heigth;
	}
}
