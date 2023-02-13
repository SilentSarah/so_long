/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:31 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/11 16:33:07 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

//PLAYER
# define PLAYER_DIR "./textures/Player/Player.xpm"

//WALLS ARE LISTENING
# define WALL_DIR "./textures/Walls/Wall.xpm"

# define MAX_MAP_SIZE 1000000
# define RES_MULTIPLIER 64

typedef struct t_map {
	int	coins;
	int	exits;
	int	players;
	int	rdata;
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
	int		oldpos[2];
}	t_data;

typedef struct t_textures {
	void	*txt[5];
	t_mlx	*mlx_data;
	t_data	*utils;
}	t_textures;

enum e_textures {
	coins = 0,
	exits = 1,
	floor = 2,
	player = 3,
	wall = 4,
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
void		flood_map(int x, int y, char **map, t_data *tools);
bool		check_remaining_items(char **test_map);
char		*ft_strdup(const char *s1);
void		check_textures(t_data *tools);
void		find_resolution(t_data *tools, t_mlx *mlx);
t_textures	*load_textures_into_memory(t_data *tools, t_mlx *mlx);
void		generate_map(t_data *tools, t_mlx *mlx);
void		display_map_elements(t_data *tools, t_mlx *mlx, t_textures *res);
int			key_response(int key_press, t_textures *res);
int			destroy_game(t_textures *res);
#endif