/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load_check_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:40:33 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/18 11:39:07 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_resolution(t_data *tools, t_mlx *mlx)
{
	mlx->h = tools->height * RES_MULTIPLIER;
	mlx->w = tools->length * RES_MULTIPLIER;
	ft_printf("Detected Resolution: %d x %d.\n", mlx->w, mlx->h);
	if (mlx->w >= 3200 || mlx->h >= 1800)
		print_error(5, tools);
}

void	check_textures(t_data *tools)
{
	int			i;
	int			fd_open;
	static char	*textures[36] = {COIN_DIR, EXIT_DIR,
		FLOOR_DIR, WALL_DIR, H_FULL, H_MID, H_LOW, EXPL_DTH, PLAYER_DIR1,
		PLAYER_DIR2, PLAYER_DIR3, PLAYER_DIR4, PLAYER_DIR5, PLAYER_DIR6,
		PLAYER_DIR7, PLAYER_DIR8, PLAYER_DIR9, PLAYER_DIRX, ENEMY_DIR1,
		ENEMY_DIR2, ENEMY_DIR3, ENEMY_DIR4, ENEMY_DIR5, ENEMY_DIR6,
		R_F1, R_F2, R_F3, R_F4, R_F5, R_F6, R_F7, R_F8, R_F9, R_FX, G_O, G_S};

	i = -1;
	ft_printf("[❗]Checking game resources...\n");
	while (++i < 36)
	{
		fd_open = open(textures[i], O_RDONLY);
		if (fd_open == -1)
		{
			ft_printf("Cannot Check Texture: %s [❌]\n", textures[i]);
			print_error(4, tools);
		}
		close(fd_open);
		ft_printf("Loading Texture: %s [✅]\n", textures[i]);
	}
	ft_printf("[✅]All game resources are in place.\n");
}

t_textures	*load_textures_into_memory(t_data *tools, t_mlx *mlx)
{
	int					i;
	static t_textures	res;
	static char			*textures[36] = {COIN_DIR, EXIT_DIR,
		FLOOR_DIR, WALL_DIR, H_FULL, H_MID, H_LOW, EXPL_DTH, PLAYER_DIR1,
		PLAYER_DIR2, PLAYER_DIR3, PLAYER_DIR4, PLAYER_DIR5, PLAYER_DIR6,
		PLAYER_DIR7, PLAYER_DIR8, PLAYER_DIR9, PLAYER_DIRX, ENEMY_DIR1,
		ENEMY_DIR2, ENEMY_DIR3, ENEMY_DIR4, ENEMY_DIR5, ENEMY_DIR6,
		R_F1, R_F2, R_F3, R_F4, R_F5, R_F6, R_F7, R_F8, R_F9, R_FX, G_O, G_S};

	i = -1;
	while (++i < 36)
	{
		res.txt[i] = mlx_xpm_file_to_image(mlx->init,
				textures[i], &mlx->w, &mlx->h);
		if (!res.txt[i])
		{
			image_destroy(&res, mlx);
			mlx_destroy_window(mlx->init, mlx->win);
			free (mlx->init);
			print_error(4, tools);
		}
	}
	res.mlx_data = mlx;
	res.utils = tools;
	return (&res);
}

void	generate_map(t_data *tools, t_mlx *mlx)
{
	t_textures	*rsc;

	rsc = load_textures_into_memory(tools, mlx);
	display_map_elements(tools, rsc);
	mlx_hook(mlx->win, 2, 0, key_response, rsc);
	mlx_hook(mlx->win, 17, 0, destroy_game, rsc);
	display_game_instructions(rsc);
	mlx_loop_hook(mlx->init, render_frames, rsc);
}
