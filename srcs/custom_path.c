/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:17:56 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 21:26:03 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	redraw_map_cp(t_game *game, int new_x, int new_y, int keycode)
{
	static int count = 0;
	if (keycode == 65307)
	{
		mlx_destroy_window(game->data->mlx, game->data->window);
		exit(0);
	}
	if (keycode == 100 || keycode == 115 || keycode == 119 || keycode == 97)
	{
		count++;
		ft_printf("move %d\n", count);
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.ground, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
	}
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	if (keycode == 100 || keycode == 115 || keycode == 119)
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.player_r, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
	else if (keycode == 97 || keycode == 115 || keycode == 119)
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.player_l, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
}

void	check_exit_cp(t_game *game, int new_x, int new_y)
{
	if (game->map->content[new_y][new_x] == 'E')
	{
		if (game->map->collectibles == 0)
		{
			finish_display(game);
			ft_printf("FINNNIIIIIIIII\n");
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

int	move_cp(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	if (keycode == 119) //w
		new_y = game->map->player_y - 1;
	else if (keycode == 115) //s
		new_y = game->map->player_y + 1;
	else if (keycode == 100) //d
		new_x = game->map->player_x + 1;
	else if (keycode == 97) // a
		new_x = game->map->player_x - 1;
	if (game->map->content[new_y][new_x] != '1')
	{
		if (game->map->content[new_y][new_x] == 'E')
		{
			if (game->map->collectibles == 0)
				redraw_map_cp(game, new_x, new_y, keycode);
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
	return (1);
}

void	custom_path(char *path)
{
	t_data	data;
	t_map	map;
	t_game	game;

		map.path = path;
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
		mlx_hook(data.window, 2, 1L<<0, key_press, &data);
		mlx_hook(data.window, 2, 1L<<0, move_cp, &game);
		mlx_hook(data.window, 17, 1L<<17, close_window, &data);
		mlx_loop(data.mlx);
}