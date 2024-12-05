/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:36:01 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/05 21:17:12 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define TILE_W 32
# define TILE_H 32
// COLOR
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BOLD "\033[1m"
# define END "\033[0m"

typedef struct s_sprites {
	void	*wall;
	void	*ground;
	void	*player_r;
	void	*player_l;
	void	*collect;
	void	*exit;
	void	*exit_blocked;
}				t_sprites;

typedef struct s_enemy {
	void	*sprites[10];
	int		current_frame;
	int		frame_count;
	int		frame_delay;
	int		frame_timer;
	int		x;
	int		y;
}				t_enemy;

typedef struct s_enemies
{
	t_enemy **enemies;
	int count;
	int capacity;
}				t_enemies;

typedef struct	s_data {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_sprites	sprites;
	t_enemies	*enemies;
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
	int		out_x;
	int		out_y;
	int		collectibles;
	int		count_out;
	int		count_player;
	int		enemy_count;
	int		frame_counter;
}				t_map;

typedef struct s_line {
	char	*line;
	int		no;
}				t_line;

typedef struct s_game {
	t_data	*data;
	t_map	*map;
}				t_game;

//hook
int close_window(t_data *data);
int mouse_press(int button, int x, int y, t_data *data);
int mouse_move(int x, int y, t_data *data);
int key_press(int keycode, t_data *data);
int	close_key_press(int keycode, t_data *data);
// experience
int img_move(int x, int y, t_data *data);
//ground_creator
void	ground_creator(t_data *data);
//wall_creator
void	wall_creator(t_data *data);
//read map
int	read_maps(t_map *map);
//check path
int	check_path(t_map *map);
// so_long_utils
int	len_line(char *line);
void	free_map(t_map *map, int i);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//testing.c
void	just_testing(t_map	*map);
//create_map
int	draw_map(t_map *map, t_data *data);
int	draw_backround(t_data *data, t_line *line);
void	place_items(t_data *data, t_line *line);
//draw lvl2
void	goto_lvl_two(t_game *game);
void	cleanup_level(t_game *game);
//Move perso
int	move(int keycode, t_game *game);
// finish display
void	finish_display(t_game *game);
void	gameover_display(t_game *game);
// custom path
void	custom_path(char *path);
// enemy
int	update_animation(t_data *data);
void	draw_enemy(t_data *data, int y, int x);
void free_enemies(t_data *data);

#endif
