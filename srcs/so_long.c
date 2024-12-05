/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:49 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/05 18:42:45 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	default_path(void)
{
	t_data	data;
	t_map	map;
	t_game	game;

	map.path = "./maps/map.ber";
	if (!read_maps(&map))
	{
		ft_printf("Error with the map\n");
		return (0);
	}
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, TILE_W * map.width, TILE_H * map.height, "so_long");
	draw_map(&map, &data);
	game.data = &data;
	game.map = &map;
	mlx_hook(data.window, 2, 1L<<0, key_press, &data);
	mlx_hook(data.window, 2, 1L<<0, move, &game);
	mlx_hook(data.window, 17, 1L<<17, close_window, &data);
	mlx_loop_hook(data.mlx, update_animation, &data);
	mlx_loop(data.mlx);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (!default_path())
			return (1);
	}
	else if (argc == 2)
		custom_path(argv[1]);
	else
		ft_printf(RED"Error, to many arguments\n"END);
}
// gerer les ennemis dnas le default path;