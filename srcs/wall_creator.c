/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:54 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/29 16:52:50 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	wall_creator(t_data *data)
{
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	char	*path_fence;
	char	*path_fence2;

	x = 0;
	y = 0;
	path_fence2 = "./assets/fence_side.xpm";
	path_fence = "./assets/fence_corner2.xpm";
	//first corner
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
	//top
	path_fence = "./assets/fence_top.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	if (!data->img)
	{
		ft_printf("error\n");
		return (0);
	}
	x = img_width;
	while (x < (WIDTH - img_width))
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		x += img_width;
	}
	//second corner
	path_fence = "./assets/fence_corner.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
	//right side
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence2, &img_width, &img_height);
	x = WIDTH - img_width;
	y = HEIGHT - (HEIGHT - img_height);
	while (y < (HEIGHT - img_height))
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		y += img_height;
	}
	//third corner
	path_fence = "./assets/fence_corner3.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
	//left side
	path_fence2 = "./assets/fence_side_2.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence2, &img_width, &img_height);
	x = 0;
	y = HEIGHT - (HEIGHT - img_height);
	while (y < (HEIGHT - img_height))
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		y += img_height;
	}
	//last corner
	path_fence = "./assets/fence_corner4.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
	//bottom
	path_fence = "./assets/fence_bottom.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx, path_fence, &img_width, &img_height);
	if (!data->img)
	{
		ft_printf("error\n");
		return (0);
	}
	x = img_width;
	y = WIDTH - img_width;
	while (x < (WIDTH - img_width))
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		x += img_width;
	}

}
