/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:20:20 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/30 00:01:20 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_line_char(char *line)
{
	int i;
	char c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '1' || c == '2' || c == 'P' || c == 'E' || c == 'C')
			i++;
		else
			return (0);
	}
	return (1);
}

int	read_maps(void)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open("./maps/map.ber", O_RDONLY);
	if (!fd)
	{
		ft_printf("erreur de lecture de la map\n");
		return (0);
	} line = "aa";
	//verifier si les char de la map sont valides (check_line_char)
	while (line)
	{
		line = get_next_line(fd);
		if (!check_line_char(line))
			return (0);
		ft_printf("test de lecture : %s\n", line);
	}
	//Peut-etre prevoir de malloc au fur et a mesure pendant la premiere verif!
	//Creer une structure dediee pour la map
	//ajouter la map dans un tableau (add_map)
	//verifier que la configuartion dfe la maop est valide (check_config_map)
	close(fd);
	return (1);
}
