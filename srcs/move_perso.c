/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:11:25 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/03 16:17:43 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	// w = 119 d = 100 s = 115 a = 97
	new_x = game->map->player_x;
	new_y = game->map->player_y;
	ft_printf("player x : %d, player y %d\n", game->map->player_x, game->map->player_y);
	if (keycode == 119)
		new_y = game->map->player_y - 1;
	else if (keycode == 115)
		new_y = game->map->player_y + 1;
	else if (keycode == 100)
		new_x = game->map->player_x + 1;
	else if (keycode == 97)
		new_x = game->map->player_x - 1;
	if (game->map->content[new_y][new_x] != '1')
	{
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.ground, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
		game->map->player_x = new_x;
		game->map->player_y = new_y;
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.player, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
	}
	return (1);
}
