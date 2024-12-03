/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lvl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:16:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/03 22:51:13 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_sprites_lvl2(t_data *data)
{
	int width;
	int height;

	// On charge chaque image une seule fois
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/wall32_lvl2.xpm", &width, &height);
	data->sprites.ground = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/ground32_lvl2.xpm", &width, &height);
	data->sprites.player_r = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/noctali32_r.xpm", &width, &height);
	data->sprites.player_l = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/noctali32_l.xpm", &width, &height);
	data->sprites.collect = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/collect32_lvl2.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/exit32_lvl2.xpm", &width, &height);
	data->sprites.exit_blocked = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/blocked_out32_lvl2.xpm", &width, &height);

    // Vérification que toutes les images sont bien chargées
	if (!data->sprites.wall || !data->sprites.ground || !data->sprites.player_r
		|| !data->sprites.collect || !data->sprites.exit
		|| !data->sprites.exit_blocked || !data->sprites.player_l)
		return (0);
	return (1);
}

int	draw_map_lvl2(t_map *map, t_data *data)
{
	int		i;
	t_line	line;

	i = 0;
	if (!init_sprites_lvl2(data))
		return (0);
	while (map->content[i])
	{
		line.line = map->content[i];
		line.no = i;
		draw_backround(data, &line);
		place_items(data, &line);
		i++;
	}
	mlx_destroy_image(data->mlx, data->sprites.wall);
	//mlx_destroy_image(data->mlx, data->sprites.ground);
	//mlx_destroy_image(data->mlx, data->sprites.player);
	//mlx_destroy_image(data->mlx, data->sprites.exit);
	mlx_destroy_image(data->mlx, data->sprites.collect);

	return (1);
}

void	goto_lvl_two(t_game *game)
{
	t_data	data2;
	t_map	map2;
	t_game	game2;

	mlx_destroy_image(game->data->mlx, game->data->sprites.ground);
	mlx_destroy_image(game->data->mlx, game->data->sprites.player_r);
	mlx_destroy_image(game->data->mlx, game->data->sprites.exit);
	mlx_destroy_window(game->data->mlx, game->data->window);
	map2.path = "./maps/lvl2.ber";
	if (!read_maps(&map2))
	{
		ft_printf("Erreur lecture map lvl 2\n");
		return ;
	}
	game2.data = &data2;
	game2.map = &map2;
	data2.mlx = mlx_init();
	data2.window = mlx_new_window(data2.mlx, TILE_W * map2.width, TILE_H * map2.height, "so_long : the cave");
	draw_map_lvl2(&map2, &data2);
	mlx_hook(data2.window, 2, 1L<<0, move, &game2);
	mlx_hook(data2.window, 17, 1L<<17, close_window, &data2);
	mlx_loop(data2.mlx);
}
/* game->map->path = "./maps/lvl2.ber";
	if (!read_maps(game->map))
	{
		ft_printf("Erreur lecture map lvl 2\n");
		return ;
	}
	game->data->mlx = mlx_init();
	game->data->window = mlx_new_window(game->data->mlx, TILE_W * game->map->width, TILE_H * game->map->height, "so_long : the cave");
	draw_map_lvl2(game->map, game->data);
	mlx_hook(game->data->window, 2, 1L<<0, move, &game);
	mlx_loop(game->data->mlx); */