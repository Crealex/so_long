/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:11:25 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/05 10:43:42 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_counter(t_game *game, int count)
{
	int		y;
	int		x;
	char	*str_count;

	y = 0;
	x = 20;
	str_count = ft_itoa(count);
	game->data->img = mlx_new_image(game->data->mlx, 90, 15);
	game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel,
		&game->data->line_length, &game->data->endian);
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
	mlx_put_image_to_window(game->data->mlx, game->data->window, game->data->img, 0, 0);
	mlx_string_put(game->data->mlx, game->data->window,10, 10, 0xFF0000, "move : ");
	mlx_string_put(game->data->mlx, game->data->window,50, 10, 0xFF0000, str_count);
}

void	redraw_map(t_game *game, int new_x, int new_y, int keycode)
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
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.ground, game->map->player_x * TILE_W, game->map->player_y * TILE_H);
		draw_counter(game, count);
		ft_printf("move %d\n", count);
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

void	check_exit(t_game *game, int new_x, int new_y)
{
	static int	lvl2_visisted = 0;

	if (game->map->content[new_y][new_x] == 'E')
	{
		if (game->map->collectibles == 0 && lvl2_visisted == 0)
		{
			lvl2_visisted = 1;
			goto_lvl_two(game);
		}
		else if (game->map->collectibles != 0)
			mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.exit_blocked, game->map->out_x * TILE_W,
			game->map->out_y * TILE_H);
		else if (game->map->collectibles == 0)
		{
			//creer image de fin
			finish_display(game);
			return ;
		}
	}
	else if (game->map->collectibles == 0)
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->sprites.exit, game->map->out_x * TILE_W,
			game->map->out_y * TILE_H);
}

int	move(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	//ft_printf("player x : %d, player y %d\n", game->map->player_x, game->map->player_y);
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
				redraw_map(game, new_x, new_y, keycode);
		}
		else
			redraw_map(game, new_x, new_y, keycode);
		if (game->map->content[new_y][new_x] == 'C')
		{
			game->map->collectibles--;
			game->map->content[new_y][new_x] = '0';
		}
		check_exit(game, new_x, new_y);
	}
	return (1);
}
