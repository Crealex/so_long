/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:26:31 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/04 15:22:18 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Fonction appelée quand on clique sur le X de la fenêtre
int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}
//fonction appelee quand on clique sur un bouton de la souris
//mlx_hook(data.window, 4, 1L<<2, mouse_press, &data);
int mouse_press(int button, int x, int y, t_data *data)
{
	(void)data;
	char *str;

	if (button == 1)
		str = "gauche";
	else if (button == 2)
		str = "molette";
	else if (button == 3)
		str = "droit";
	printf("Position de la souris au clic %s : x:%d y: %d\n", str, x, y);
}
//fonction appelee au mouvement de la souris
int mouse_move(int x, int y, t_data *data)
{
	//ft_printf("Coordonees de la souris x : %d y : %d\n", x, y);
	img_move(x, y, data);
}
//Fonction appelee a l'appui d'une touche
int key_press(int keycode, t_data *data)
{
    // 65307 est le code de la touche ESC
	ft_printf("keycode : %d\n", keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->window);
        exit(0);
    }
	return (0);
}