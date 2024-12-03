/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:20:20 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/03 22:10:42 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_line_char(char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C'
			|| c == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	file_to_map(t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(map->path, O_RDONLY);
	map->content = malloc(sizeof(char *) * (map->height + 1));
	if (!map->content)
		return (0);
	i = 0;
	while (i <= map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->width != len_line(line))
			return (0);
		map->content[i] = ft_strdup(line);
		i++;
	}
	i++;
	map->content[i] = NULL;
	close(fd);
	return (1);
}

int	char_check(char c, t_map *map, int i, int j)
{
	if (c == 'C')
		map->collectibles++;
	if (c == 'E')
	{
		map->count_out++;
		map->out_x = j;
		map->out_y = i;
	}
	if (c == 'P')
	{
		map->count_player++;
		map->player_x = j;
		map->player_y = i;
	}
	if ((i == (map->height - 1) || i == 0) || j == 0
		|| j == (map->width - 1))
		{
			if (map->content[i][j] != '1'
				&& map->content[i][j] != '\n')
				return (0);
		}
	return (1);
}

int	is_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->count_out = 0;
	map->count_player = 0;
	map->collectibles = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->content[i][j])
		{
			if (!char_check(map->content[i][j], map, i , j))
				return (0);
			j++;
		}
		i++;
	}
	if (map->count_player != 1 || map->count_out != 1
		|| map->collectibles < 1)
		return (0);
	return (1);
}

int	read_maps(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (!fd)
		return (0);
	map->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!check_line_char(line))
			return (0);
		map->height++;
		map->width = ft_strlen(line);
	}
	close(fd);
	if (!file_to_map(map))
		return (0);
	if (!is_valid(map))
		return (0);
	 if (!check_path(map))
		return (0);
	return (1);
}
