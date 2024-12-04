/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:01:48 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 10:27:34 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	len_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	free_map(t_map *map, int i)
{
	if (!map)
		return ;
	if (map->content)
	{
		while (i >= 0)
		{
			free(map->content[i]);
			i--;
		}
		free(map->content);
	}
	free(map);
}
