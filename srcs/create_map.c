/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:28:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/02 17:09:10 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_items(t_data *data, t_line *line)
{
	int		j;
	t_img	exit;
	t_img	collect;
	t_img	perso;

	j = 0;
	exit.img = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm",
			&exit.width, &exit.height);
	collect.img = mlx_xpm_file_to_image(data->mlx, "./assets/collect.xpm",
			&collect.width, &collect.height);
	perso.img = mlx_xpm_file_to_image(data->mlx, "./assets/evoli2.xpm",
			&perso.width, &perso.height);
	while (line->line[j])
	{
		if (line->line[j] == 'C')
			mlx_put_image_to_window(data->mlx, data->window, collect.img,
				(j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, exit.img,
				(j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == 'P')
			mlx_put_image_to_window(data->mlx, data->window, perso.img,
				(j * TILE_W), (line->no * TILE_H));
		j++;
	}
}

int	create_backround(t_img *wall, t_img *ground, t_data *data, t_line *line)
{
	int	j;

	j = 0;
	while (line->line[j])
	{
		if (line->line[j] == '0')
			mlx_put_image_to_window(data->mlx, data->window, ground->img,
				(j * TILE_W), (line->no * TILE_H));
		else if (line->line[j] == '1')
			mlx_put_image_to_window(data->mlx, data->window, wall->img,
				(j * TILE_W), (line->no * TILE_H));
		j++;
	}
	return (1);
}

int	create_map(t_map *map, t_data *data)
{
	int		i;
	int		j;
	t_img	wall;
	t_img	ground;
	t_line	line;

	i = 0;
	j = 0;
	wall.path = "./assets/wall.xpm";
	ground.path = "./assets/grass.xpm";
	wall.img = mlx_xpm_file_to_image(data->mlx, wall.path,
			&wall.width, &wall.height);
	ground.img = mlx_xpm_file_to_image(data->mlx, ground.path,
			&ground.width, &ground.height);
	while (map->content[i])
	{
		line.line = map->content[i];
		line.no = i;
		create_backround(&wall, &ground, data, &line);
		place_items(data, &line);
		i++;
	}
	return (1);
}
