/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:49 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 15:26:05 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_game	game;
	if (argc == 1)
	{
		map.path = "./maps/map.ber";
		if (!read_maps(&map))
		{
			ft_printf("Error with the map\n");
			return (1);
		}
		data.mlx = mlx_init();
		data.window = mlx_new_window(data.mlx, TILE_W * map.width, TILE_H * map.height, "so_long");
		draw_map(&map, &data);
		game.data = &data;
		game.map = &map;
		ft_printf("player x : %d, player y %d\n", map.player_x, map.player_y);
		ft_printf("player x : %d, player y %d\n", game.map->player_x, game.map->player_y);
		mlx_hook(data.window, 2, 1L<<0, key_press, &data);
		mlx_hook(data.window, 2, 1L<<0, move, &game);
		mlx_loop(data.mlx);
		mlx_hook(data.window, 17, 1L<<17, close_window, &data);
	}
	else if (argc == 2)
	{
		map.path = argv[1];
	}
	else
	{
		ft_printf(RED"Error, to many arguments\n"END);
	}

}
