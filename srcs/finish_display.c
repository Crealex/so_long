/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:27:27 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 22:05:49 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_display(t_game *game)
{
	int width;
	int height;
	void	*img;

	cleanup_level(game);
	game->data->mlx = mlx_init();
	 if (!game->data->mlx)
    {
        ft_printf("Erreur d'initialisation MLX\n");
        return;
    }
	game->data->window = mlx_new_window(game->data->mlx, 1024,
		1024, "so_long : finish");
	 if (!game->data->window)
    {
        ft_printf("Erreur de création de la fenêtre\n");
        return;
    }
	img = mlx_xpm_file_to_image(game->data->mlx,
		"./assets/32px/final_v1.xpm", &width, &height);
	if (!img)
	{
		ft_printf("image pas chargee\n");
		return ;
	}
	mlx_put_image_to_window(game->data->mlx, game->data->window, img, 0, 0);
	ft_printf("testtttt\n");
	mlx_hook(game->data->window, 17, 1L<<17, close_window, game->data);
	mlx_hook(game->data->window, 2, 1L<<0, close_key_press, game->data);
	//mlx_destroy_image(game->data->mlx, img);
	mlx_loop(game->data->mlx);
}
