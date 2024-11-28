/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:49 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/28 15:25:34 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_data	data;
	//int x;
	//int y;
	char	*relative_path = "./assets/evoli.xpm";
	int		img_width;
	int		img_height;

	//x = 20;
	//y = 20;
	img_height = 475;
	img_width = 475;
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 1920, 1080, "Ma premiere fenetre");
	data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &img_width, &img_height);
	if (!data.img)
	{
		ft_printf("error\n");
		return (0);
	}
	/* data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	while (y < 40)
	{
		y++;
		x = 20;
		while (x < 40)
		{
			my_mlx_pixel_put(&data, x, y, 0x00FF0000);
			x++;
		}
	} */

	mlx_put_image_to_window(data.mlx, data.window, data.img, 20, 20);
	mlx_hook(data.window, 2, 1L<<0, key_press, &data);
	mlx_hook(data.window, 17, 1L<<17, close_window, &data);
	mlx_hook(data.window, 4, 1L<<2, mouse_press, &data);
	mlx_hook(data.window, 6, 1L<<6, mouse_move, &data);
	mlx_loop(data.mlx);
}
