/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:28:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/03 16:07:00 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_items(t_data *data, t_line *line)
{
	int		j;

	j = 0;
	while (line->line[j])
	{
		if (line->line[j] == 'C')
			mlx_put_image_to_window(data->mlx, data->window,
			data->sprites.collect, (j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->sprites.exit,
				(j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == 'P')
			mlx_put_image_to_window(data->mlx, data->window,
				data->sprites.player, (j * TILE_W), (line->no * TILE_H));
		j++;
	}
}

int	draw_backround(t_data *data, t_line *line)
{
	int	j;

	j = 0;
	while (line->line[j])
	{
		if (line->line[j] == '0')
			mlx_put_image_to_window(data->mlx, data->window,
			data->sprites.ground, (j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->sprites.wall,
				(j * TILE_W), (line->no * TILE_H));
		j++;
	}
	return (1);
}

int	init_sprites(t_data *data)
{
	int width;
	int height;

	// On charge chaque image une seule fois
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/wall32.xpm", &width, &height);
	data->sprites.ground = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/grass32.xpm", &width, &height);
    data->sprites.player = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/evoli_r.xpm", &width, &height);
	data->sprites.collect = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/collect32.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image(data->mlx,
		"./assets/32px/exit32.xpm", &width, &height);

    // Vérification que toutes les images sont bien chargées
	if (!data->sprites.wall || !data->sprites.ground || !data->sprites.player
		|| !data->sprites.collect|| !data->sprites.exit)
		return (0);
	return (1);
}

int	draw_map(t_map *map, t_data *data)
{
	int		i;
	t_line	line;

	i = 0;
	if (!init_sprites(data))
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
	mlx_destroy_image(data->mlx, data->sprites.exit);
	mlx_destroy_image(data->mlx, data->sprites.collect);

	return (1);
}
