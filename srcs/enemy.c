/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:15:54 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/06 15:41:35 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_animation(t_data *data)
{
	int		i;
	t_enemy	*current;

	i = 0;
	if (!data || !data->enemies || !data->enemies->enemies)
		return (0);
	while (i < data->enemies->count)
	{
		current = data->enemies->enemies[i];
		current->frame_timer++;
		if (current->frame_timer >= current->frame_delay)
		{
			current->frame_timer = 0;
			current->current_frame++;
			if (current->current_frame >= current->frame_count)
				current->current_frame = 0;
			mlx_put_image_to_window(data->mlx, data->window,
				current->sprites[current->current_frame],
				current->x * TILE_W, current->y * TILE_H);
		}
		i++;
	}
	return (0);
}

void	init_sprites_path(char *sprites_path[])
{
	sprites_path[0] = "./assets/32px/smogo/frame_1.xpm";
	sprites_path[1] = "./assets/32px/smogo/frame_2.xpm";
	sprites_path[2] = "./assets/32px/smogo/frame_3.xpm";
	sprites_path[3] = "./assets/32px/smogo/frame_4.xpm";
	sprites_path[4] = "./assets/32px/smogo/frame_5.xpm";
	sprites_path[5] = "./assets/32px/smogo/frame_6.xpm";
	sprites_path[6] = "./assets/32px/smogo/frame_7.xpm";
	sprites_path[7] = "./assets/32px/smogo/frame_8.xpm";
	sprites_path[8] = "./assets/32px/smogo/frame_9.xpm";
	sprites_path[9] = "./assets/32px/smogo/frame_10.xpm";
}

void	init_enemy(t_data *data, t_enemy *enemy, int x, int y)
{
	int		i;
	int		width;
	int		height;
	char	*sprites_path[10];

	init_sprites_path(sprites_path);
	enemy->x = x;
	enemy->y = y;
	enemy->current_frame = 0;
	enemy->frame_count = 10;
	enemy->frame_delay = 5000;
	enemy->frame_timer = 0;
	i = 0;
	while (i < enemy->frame_count)
	{
		enemy->sprites[i] = mlx_xpm_file_to_image(data->mlx,
				sprites_path[i], &width, &height);
		if (!enemy->sprites[i])
		{
			return ;
		}
		i++;
	}
}

static int	init_enemies_structure(t_data *data)
{
	data->enemies = ft_calloc(sizeof(t_enemies), 1);
	if (!data->enemies)
		return (0);
	data->enemies->capacity = 50;
	data->enemies->count = 0;
	data->enemies->enemies = ft_calloc(sizeof(t_enemy *),
			data->enemies->capacity);
	if (!data->enemies->enemies)
	{
		free(data->enemies);
		data->enemies = NULL;
		return (0);
	}
	return (1);
}

void	draw_enemy(t_data *data, int x, int y)
{
	t_enemy	*new_enemy;

	if (!data->enemies && !init_enemies_structure(data))
		return ;
	if (data->enemies->count >= data->enemies->capacity)
		return ;
	new_enemy = ft_calloc(sizeof(t_enemy), 1);
	if (!new_enemy)
		return ;
	init_enemy(data, new_enemy, x, y);
	data->enemies->enemies[data->enemies->count] = new_enemy;
	data->enemies->count++;
}
