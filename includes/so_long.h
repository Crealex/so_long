/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:36:01 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/29 14:44:55 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_data {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//hook
int close_window(t_data *data);
int mouse_press(int button, int x, int y, t_data *data);
int mouse_move(int x, int y, t_data *data);
int key_press(int keycode, t_data *data);
// experience
int img_move(int x, int y, t_data *data);
//ground_creator
void	ground_creator(t_data *data);
//wall_creator
void	wall_creator(t_data *data);

#endif
