/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_textures_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:40:43 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/15 10:55:01 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_destroy(t_textures *res, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 35)
		if (res->txt[i])
			mlx_destroy_image(mlx->init, res->txt[i]);
}

void	display_sprites(t_textures *res, int x, int y)
{
	mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
		res->txt[floor], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	if (res->utils->matrix[y][x] == '1')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[wall], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'C')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[coins], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'P')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[player], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'E')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[exits], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'X')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[enemy], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
}

void	display_map_elements(t_data *tools, t_textures *res)
{
	int	x;
	int	y;

	y = -1;
	while (++y < tools->height)
	{
		x = -1;
		while (++x < tools->length)
			display_sprites(res, x, y);
	}
}

void	update_frames(t_textures *res, int *ticks)
{
	int	i;
	int	j;

	i = -1;
	if (*ticks % 240 == 0)
	{
		i = -1;
		while (res->utils->matrix[++i])
		{
			j = -1;
			while (res->utils->matrix[i][++j])
			{
				display_counters(res);
				refresh_sprites(res, j, i);
			}
		}
	}
}
