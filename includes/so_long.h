/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:36:01 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/02 13:47:19 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define TILE_W 40
# define TILE_H 40

typedef struct	s_data {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
	char	*path;
}				t_img;

typedef struct s_map {
	char	**content;
	char	*path;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		count_out;
	int		count_player;
}				t_map;

typedef struct s_line {
	char	*line;
	int		no;
}				t_line;

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
//read map
int	read_maps(t_map *map);
// so_long_utils
int	len_line(char *line);
//testing.c
void	just_testing(t_map	*map);
//create_map
int	create_map(t_map *map, t_data *data);

#endif
