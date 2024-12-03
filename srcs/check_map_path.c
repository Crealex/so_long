/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:58:01 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/03 11:39:09 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map_copy(t_map *map)
{
	t_map *map_cpy;
	int i;
	map_cpy = malloc(sizeof(t_map));
	if (!map_cpy)
		return (NULL);
	map_cpy->content = malloc(sizeof(char *) * (map->height + 1));
	if (!map_cpy->content)
		return (free(map_cpy), NULL);
	i = 0;
	while (map->content[i])
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
	map->count_out = map->count_out;
	map_cpy->player_x = map->player_x;
	map_cpy->player_y = map->player_y;
	return (map_cpy);
}

flood_fill(t_map *map, int x, int y)
{
	if  (map->content[y][x] == '1' || map->content[y][x] == 'V')
		return ;
	if (map->content[y][x] == 'C')
		map->collectibles--;
	if (map->content[y][x] == 'E')
		map->count_out--;
	map->content[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_path(t_map *map)
{
	int i;
	int j;
	t_map	*map_cpy;

	i = 0;
	j = 0;
	ft_printf("test\n");
	map_cpy = map_copy(map);
	flood_fill(map_cpy, map_cpy->player_x, map_cpy->player_y);
	if (map_cpy->collectibles != 0 || map_cpy->count_out != 0)
		return (0);
	return (1);
}