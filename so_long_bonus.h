/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:31 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/13 12:33:48 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include "sources/ft_printf.h"

# define INV_EXT "[❌]Error: Invalid File Extension!\n"
# define OPN_ERR "[❌]Error: The map file cannot be opened!\n"
# define EL_INV "[❌]Error: The map format is invalid!\n"
# define PATH_ERR "[❌]Error: The map doesn't contain a valid path!\n"
# define TXT_ERR "[❌]Error: Cannot load game resources!\n"
# define RES_ERR "[❌]Error: Resolution of the map is higher than the mac!\n"
# define MLX_ERROR "[❌]Error: Cannot connect to the display!\n"

// MAP ITEMS
# define COIN_DIR "./textures/Coins/Coin.xpm"
# define EXIT_DIR "./textures/Exit/Door.xpm"

//MOVING GROUND
# define FLOOR_DIR "./textures/Floor/Floor.xpm"

//WALLS ARE LISTENING
# define WALL_DIR "./textures/Walls/Wall.xpm"

//Health for the player
# define HEART_DIR "./textures/Bonus/Health/Hearts.xpm"

//PLAYER
# define PLAYER_DIR1 "./textures/Bonus/Player/PF_1.xpm"
# define PLAYER_DIR2 "./textures/Bonus/Player/PF_2.xpm"
# define PLAYER_DIR3 "./textures/Bonus/Player/PF_3.xpm"
# define PLAYER_DIR4 "./textures/Bonus/Player/PF_4.xpm"
# define PLAYER_DIR5 "./textures/Bonus/Player/PF_5.xpm"
# define PLAYER_DIR6 "./textures/Bonus/Player/PF_6.xpm"
# define PLAYER_DIR7 "./textures/Bonus/Player/PF_7.xpm"
# define PLAYER_DIR8 "./textures/Bonus/Player/PF_8.xpm"
# define PLAYER_DIR9 "./textures/Bonus/Player/PF_9.xpm"
# define PLAYER_DIRX "./textures/Bonus/Player/PF_X.xpm"

//ENEMY
# define ENEMY_DIR1 "./textures/Bonus/Enemy/EF_1.xpm"
# define ENEMY_DIR2 "./textures/Bonus/Enemy/EF_2.xpm"
# define ENEMY_DIR3 "./textures/Bonus/Enemy/EF_3.xpm"
# define ENEMY_DIR4 "./textures/Bonus/Enemy/EF_4.xpm"
# define ENEMY_DIR5 "./textures/Bonus/Enemy/EF_5.xpm"
# define ENEMY_DIR6 "./textures/Bonus/Enemy/EF_6.xpm"

# define MAX_MAP_SIZE 1000000
# define RES_MULTIPLIER 64

typedef struct t_map {
	int		coins;
	int		exits;
	int		players;
	int		enemies;
	int		rdata;
	int		s_moves;
	int		health;
}	t_map;

typedef struct t_mlx {
	void	*init;
	void	*win;
	int		h;
	int		w;
	t_map	*map_data;
}	t_mlx;

typedef struct t_data {
	char	**matrix;
	int		height;
	int		length;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		e_oldpos[2];
	int		oldpos[2];
}	t_data;

typedef struct t_textures {
	void		*txt[21];
	t_mlx		*mlx_data;
	t_data		*utils;
}	t_textures;

enum e_textures {
	coins = 0,
	exits = 1,
	floor = 2,
	wall = 3,
	heart = 4,
	player = 5,
	enemy = 15,
};

enum e_directions {
	up = 13,
	left = 0,
	down = 1,
	right = 2,
};

void		print_error(int id, t_data *tools);
void		check_map_extension(char *map_name, t_data *tools);
int			open_map(char *map_name, t_data *tools);
char		**extract_map(char *map_name,
				t_data *tools, int (*f)(char *, t_data *));
void		initiate_window(t_mlx *mlx, t_data *tools);
void		check_map_elements(t_data *tools, t_map *map_data, t_mlx *mlx);
void		initialize_data(t_data *tools, t_map *map_data);
char		**clone_map(t_data *tools);
void		free_2d_arr(char **matrix, int len);
void		check_map_dimensions(t_data *tools);
void		check_map_walls(t_data *tools);
void		find_player_pos(t_data *tools);
void		find_enemy_pos(t_data *tools);
void		flood_map(int x, int y, char **map, t_data *tools);
bool		check_remaining_items(char **test_map);
char		*ft_strdup(const char *s1);
void		check_textures(t_data *tools);
void		find_resolution(t_data *tools, t_mlx *mlx);
t_textures	*load_textures_into_memory(t_data *tools, t_mlx *mlx);
void		generate_map(t_data *tools, t_mlx *mlx);
void		display_map_elements(t_data *tools, t_textures *res);
int			key_response(int key_press, t_textures *res);
int			destroy_game(t_textures *res);
void		analyse_map(t_data *tools, t_map *map_data);
int			render_frames(t_textures *res);
void		image_destroy(t_textures *res, t_mlx *mlx);
int			get_color(int t, int r, int g, int b);
bool		bot_awareness(t_textures *res);
void		enemy_reaction(t_textures *res);
void		move_bot_left(t_data *tools);
void		move_bot_right(t_data *tools);
void		move_bot_up(t_data *tools);
void		move_bot_down(t_data *tools);
void		patrol_map(t_textures *res, t_data *tools);
#endif