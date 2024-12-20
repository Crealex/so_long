/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lvl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:16:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/06 15:39:20 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_sprites_lvl2(t_data *data)
{
	int	width;
	int	height;

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
	while (i < map->height)
	{
		line.line = map->content[i];
		line.no = i;
		draw_backround(data, &line);
		place_items(data, &line);
		i++;
	}
	return (1);
}

void	cleanup_level(t_game *game)
{
	free_enemies(game->data);
	if (game->data->sprites.ground)
		mlx_destroy_image(game->data->mlx, game->data->sprites.ground);
	if (game->data->sprites.wall)
		mlx_destroy_image(game->data->mlx, game->data->sprites.wall);
	if (game->data->sprites.player_r)
		mlx_destroy_image(game->data->mlx, game->data->sprites.player_r);
	if (game->data->sprites.player_l)
		mlx_destroy_image(game->data->mlx, game->data->sprites.player_l);
	if (game->data->sprites.collect)
		mlx_destroy_image(game->data->mlx, game->data->sprites.collect);
	if (game->data->sprites.exit)
		mlx_destroy_image(game->data->mlx, game->data->sprites.exit);
	if (game->data->sprites.exit_blocked)
		mlx_destroy_image(game->data->mlx,
			game->data->sprites.exit_blocked);
	if (game->data->window)
		mlx_destroy_window(game->data->mlx, game->data->window);
	if (game->data->mlx)
	{
		mlx_destroy_display(game->data->mlx);
		free(game->data->mlx);
		game->data->mlx = NULL;
	}
}

void	goto_lvl_two(t_game *game)
{
	if (game->data)
		cleanup_level(game);
	game->map = ft_calloc(sizeof(t_map), 1);
	game->data = ft_calloc(sizeof(t_data), 1);
	game->data->enemies = NULL;
	game->map->path = "./maps/lvl2.ber";
	if (!read_maps(game->map))
	{
		ft_printf(RED"Error\nThe map is not valid !\n"END);
		return ;
	}
	game->data->mlx = mlx_init();
	game->data->window = mlx_new_window(game->data->mlx,
			TILE_W * game->map->width,
			TILE_H * game->map->height, "so_long : the cave");
	draw_map_lvl2(game->map, game->data);
	mlx_hook(game->data->window, 2, 1L << 0, move, game);
	mlx_hook(game->data->window, 17, 1L << 17, close_window, game->data);
	mlx_loop_hook(game->data->mlx, update_animation, game->data);
	mlx_loop(game->data->mlx);
}
