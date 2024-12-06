/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:03:16 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/06 15:04:05 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_rectangle(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 20;
	if (game->data->img)
		mlx_destroy_image(game->data->mlx, game->data->img);
	game->data->img = mlx_new_image(game->data->mlx, 90, 15);
	game->data->addr = mlx_get_data_addr(game->data->img,
			&game->data->bits_per_pixel, &game->data->line_length,
			&game->data->endian);
	while (y < 15)
	{
		y++;
		x = 20;
		while (x < 70)
		{
			my_mlx_pixel_put(game->data, x, y, 0x00000000);
			x++;
		}
	}
}

void	draw_counter(t_game *game, int count)
{
	char	*str_count;

	str_count = ft_itoa(count);
	draw_rectangle(game);
	mlx_put_image_to_window(game->data->mlx, game->data->window,
		game->data->img, 0, 0);
	mlx_string_put(game->data->mlx, game->data->window, 10, 10,
		0xFF0000, "move : ");
	mlx_string_put(game->data->mlx, game->data->window, 50, 10,
		0xFF0000, str_count);
	free(str_count);
}
