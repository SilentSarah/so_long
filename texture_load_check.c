/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:07:32 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/11 18:18:23 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_resolution(t_data *tools, t_mlx *mlx)
{
	mlx->h = tools->height * RES_MULTIPLIER;
	mlx->w = tools->length * RES_MULTIPLIER;
	ft_printf("Detected Resolution: %d x %d.\n", mlx->w, mlx->h);
	if (mlx->w >= 5120 || mlx->h >= 2880)
		print_error(5, tools);
}

void	image_destroy(t_textures *res, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (res->txt[i])
			mlx_destroy_image(mlx->init, res->txt[i]);
}

void	check_textures(t_data *tools)
{
	int			i;
	int			fd_open;
	static char	*textures[5] = {COIN_DIR, EXIT_DIR, FLOOR_DIR, PLAYER_DIR,
		WALL_DIR};

	i = -1;
	ft_printf("[❗]Checking game resources...\n");
	while (++i < 5)
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
	static t_textures	res;
	static char			*textures[5] = {PLAYER_DIR,
		COIN_DIR, EXIT_DIR, FLOOR_DIR, WALL_DIR};

	res.txt[player] = mlx_xpm_file_to_image(mlx->init,
			textures[0], &mlx->w, &mlx->h);
	res.txt[coins] = mlx_xpm_file_to_image(mlx->init,
			textures[1], &mlx->w, &mlx->h);
	res.txt[exits] = mlx_xpm_file_to_image(mlx->init,
			textures[2], &mlx->w, &mlx->h);
	res.txt[floor] = mlx_xpm_file_to_image(mlx->init,
			textures[3], &mlx->w, &mlx->h);
	res.txt[wall] = mlx_xpm_file_to_image(mlx->init,
			textures[4], &mlx->w, &mlx->h);
	if (!res.txt[player] || !res.txt[coins] || !res.txt[exits]
		|| !res.txt[floor] || !res.txt[wall])
	{
		image_destroy(&res, mlx);
		mlx_destroy_window(mlx->init, mlx->win);
		free (mlx->init);
		print_error(4, tools);
	}
	res.mlx_data = mlx;
	res.utils = tools;
	return (&res);
}

void	generate_map(t_data *tools, t_mlx *mlx)
{
	t_textures	*rsc;

	rsc = load_textures_into_memory(tools, mlx);
	display_map_elements(tools, mlx, rsc);
	mlx_hook(mlx->win, 2, 0, key_response, rsc);
	mlx_hook(mlx->win, 17, 0, destroy_game, rsc);
}
