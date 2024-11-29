/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:54 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/29 19:43:27 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	wall_creator(t_data *data)
{
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	t_img	rock;

	x = 0;
	y = 0;
	rock.path = "./assets/wall.xpm";
	rock.img = mlx_xpm_file_to_image(data->mlx, rock.path, &rock.width, &rock.height);
	if (!rock.img)
	{
		ft_printf("error\n");
		return (0);
	}
	//top
	while (x < WIDTH)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		x += img_width;
	}
	//right side
	data->img = mlx_xpm_file_to_image(data->mlx, rock.path, &img_width, &img_height);
	x = WIDTH - img_width;
	y = HEIGHT - (HEIGHT - img_height);
	while (y < HEIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		y += img_height;
	}
	//left side
	data->img = mlx_xpm_file_to_image(data->mlx, rock.path, &img_width, &img_height);
	x = 0;
	y = HEIGHT - (HEIGHT - img_height);
	while (y < HEIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		y += img_height;
	}
	//bottom
	data->img = mlx_xpm_file_to_image(data->mlx, rock.path, &img_width, &img_height);
	if (!data->img)
	{
		ft_printf("error\n");
		return (0);
	}
	x = img_width;
	y = WIDTH - img_width;
	while (x < WIDTH)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->img, x, y);
		x += img_width;
	}

}
