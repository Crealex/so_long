/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:17:56 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/06 15:39:38 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit_cp(t_game *game, int new_x, int new_y)
{
	if ((game->map->content[new_y][new_x] == 'X'))
		gameover_display(game);
	if (game->map->content[new_y][new_x] == 'E')
	{
		if (game->map->collectibles == 0)
		{
			finish_display(game);
		}
		else if (game->map->collectibles != 0)
			mlx_put_image_to_window(game->data->mlx, game->data->window,
				game->data->sprites.exit_blocked, game->map->out_x * TILE_W,
				game->map->out_y * TILE_H);
	}
	else if (game->map->collectibles == 0)
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.exit, game->map->out_x * TILE_W,
			game->map->out_y * TILE_H);
}

void	check_move_cp(t_game *game, int new_y, int new_x, int keycode)
{
	if (game->map->content[new_y][new_x] != '1')
	{
		if (game->map->content[new_y][new_x] == 'E')
		{
			if (game->map->collectibles == 0)
				redraw_map(game, new_x, new_y, keycode);
		}
		else
			redraw_map(game, new_x, new_y, keycode);
		if (game->map->content[new_y][new_x] == 'C')
		{
			game->map->collectibles--;
			game->map->content[new_y][new_x] = '0';
		}
		check_exit_cp(game, new_x, new_y);
	}
}

int	move_cp(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	if (keycode == 119)
		new_y = game->map->player_y - 1;
	else if (keycode == 115)
		new_y = game->map->player_y + 1;
	else if (keycode == 100)
		new_x = game->map->player_x + 1;
	else if (keycode == 97)
		new_x = game->map->player_x - 1;
	check_move_cp(game, new_y, new_x, keycode);
	return (1);
}

void	custom_path(char *path)
{
	t_data	data;
	t_map	*map;
	t_game	game;

	map = ft_calloc(sizeof(t_map), 1);
	map->path = path;
	if (!read_maps(map))
	{
		ft_printf(RED"Error\nThe map is not valid !\n"END);
		return ;
	}
	data.enemies = NULL;
	data.img = NULL;
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, TILE_W * map->width,
			TILE_H * map->height, "so_long");
	draw_map(map, &data);
	game.data = &data;
	game.map = map;
	mlx_hook(data.window, 2, 1L << 0, move_cp, &game);
	mlx_hook(data.window, 17, 1L << 17, close_window, &data);
	mlx_loop_hook(data.mlx, update_animation, &data);
	mlx_loop(data.mlx);
}
