/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experience.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:28:19 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/28 15:40:37 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int img_move(int x, int y, t_data *data)
{
	void *img;
	char *relative_path = "./assets/pokeball.xpm";
	int img_width;
	int img_height;
	img = mlx_xpm_file_to_image(data->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->window, img, (x - x / 2), (y - y / 2));
}