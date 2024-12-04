/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:05:48 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 14:30:44 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	just_testing(t_map	*map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->content[i]);
		i++;
	}
}