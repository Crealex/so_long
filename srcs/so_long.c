/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:49 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/29 23:41:49 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main()
{
	t_data	data;
	char *img_path;
	int img_width;
	int	img_height;

	read_maps();
	img_path = "./assets/evoli2.xpm";
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	ground_creator(&data);
	wall_creator(&data);
	data.img = mlx_xpm_file_to_image(data.mlx, img_path, &img_width, &img_height);
	mlx_put_image_to_window(data.mlx, data.window, data.img, 50, 50);


	//mlx_mouse_hide(data.mlx, data.window);
	mlx_hook(data.window, 2, 1L<<0, key_press, &data);
	mlx_hook(data.window, 17, 1L<<17, close_window, &data);
	mlx_hook(data.window, 4, 1L<<2, mouse_press, &data);
	//mlx_hook(data.window, 6, 1L<<6, mouse_move, &data);
	mlx_loop(data.mlx);
}
