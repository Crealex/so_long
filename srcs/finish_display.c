/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:27:27 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 16:42:15 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_display(t_game *game)
{
	int width;
	int height;
	void	*img;

	cleanup_level(game);
	mlx_loop_end(game->data->mlx);
	ame->data->mlx = mlx_init();
	game->data->window = mlx_new_window(game->data->mlx, TILE_W * game->map->width,
		TILE_H * game->map->height, "so_long : the cave");
	img = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/finish_v1.xpm", &width, &height);
	mlx_put_image_to_window(game->data->mlx, game->data->window...)
}