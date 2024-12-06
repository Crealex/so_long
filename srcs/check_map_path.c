/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:58:01 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/06 15:38:47 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map_copy(t_map *map)
{
	t_map	*map_cpy;
	int		i;

	map_cpy = ft_calloc(sizeof(t_map), 1);
	if (!map_cpy)
		return (NULL);
	map_cpy->content = ft_calloc(sizeof(char *), (map->height + 1));
	if (!map_cpy->content)
		return (free(map_cpy), NULL);
	i = 0;
	while (i < map->height)
	{
		map_cpy->content[i] = ft_strdup(map->content[i]);
		if (!map_cpy->content[i])
			return (free_map(map_cpy, i), NULL);
		i++;
	}
	map_cpy->content[i] = NULL;
	map_cpy->collectibles = map->collectibles;
	map_cpy->height = map->height;
	map_cpy->width = map->width;
	map_cpy->count_out = map->count_out;
	map_cpy->player_x = map->player_x;
	map_cpy->player_y = map->player_y;
	return (map_cpy);
}

int	flood_fill(t_map *map, int x, int y)
{
	if (map->content[y][x] == 'E')
	{
		map->content[y][x] = 'V';
		map->count_out--;
	}
	if (map->content[y][x] == '1' || map->content[y][x] == 'V'
			|| map->content[y][x] == 'E' || map->content[y][x] == 'X')
		return (0);
	if (map->content[y][x] == 'C')
		map->collectibles--;
	map->content[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	if (map->collectibles != 0 || map->count_out != 0)
		return (0);
	return (1);
}

int	check_path(t_map *map)
{
	t_map	*map_cpy;

	map_cpy = map_copy(map);
	if (!map_cpy)
		return (0);
	if (!flood_fill(map_cpy, map_cpy->player_x, map_cpy->player_y))
	{
		free_map(map_cpy, map_cpy->height - 1);
		return (0);
	}
	free_map(map_cpy, map_cpy->height - 1);
	return (1);
}
