/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:15:54 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/05 16:36:16 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_animation(t_data *game)
{
	int i;

	i = 0;
	ft_printf("test\n");
	while (i < game->map->enemy_count)
	{
		game->map->enemies[i].frame_timer++;
		if (game->map->enemies[i].frame_timer >= game->map->enemies[i].frame_delay)
		{
			game->map->enemies[i].frame_timer = 0;
			game->map->enemies[i].current_frame++;
			if (game->map->enemies[i].current_frame >= game->map->enemies[i].frame_count)
				game->map->enemies[i].current_frame = 0;
		}
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->map->enemies[i].sprites[game->map->enemies[i].current_frame],
			game->map->enemies[i].x * TILE_W,
			game->map->enemies[i].y * TILE_H);
		i++;
	}
	return (0);
}

void init_sprites_path(char *sprites_path[])
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
	int i;
	int width;
	int height;
	char *sprites_path[10];

	init_sprites_path(sprites_path);
	enemy->x = x;
	enemy->y = y;
	enemy->current_frame = 0;
	enemy->frame_count = 10;
	enemy->frame_delay = 10;
	enemy->frame_timer = 0;
	i = 0;
	while (i < enemy->frame_count)
	{
		enemy->sprites[i] = mlx_xpm_file_to_image(data->mlx,
			sprites_path[i], &width, &height);
		if (!enemy->sprites[i])
		{
			ft_printf("erreur du sprite");
			return ;
		}
		i++;
	}
}

void	draw_enemy(t_data *data, int y, int x)
{
	t_enemy *enemy;

	enemy = malloc(sizeof(t_enemy));
	init_enemy(data, enemy, x, y);
}
