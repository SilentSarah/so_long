/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:02:28 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/09 19:08:58 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map_elements(t_data *tools, t_mlx *mlx, t_textures *res)
{
	int	x;
	int	y;

	y = -1;
	while (++y < tools->height)
	{
		x = -1;
		while (++x < tools->length)
		{
			mlx_put_image_to_window(mlx->init, mlx->win, res->txt[floor],
				x * RES_MULTIPLIER, y * RES_MULTIPLIER);
			if (tools->matrix[y][x] == '1')
				mlx_put_image_to_window(mlx->init, mlx->win, res->txt[wall],
					x * RES_MULTIPLIER, y * RES_MULTIPLIER);
			else if (tools->matrix[y][x] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->win, res->txt[coins],
					x * RES_MULTIPLIER, y * RES_MULTIPLIER);
			else if (tools->matrix[y][x] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->win, res->txt[player],
					x * RES_MULTIPLIER, y * RES_MULTIPLIER);
			else if (tools->matrix[y][x] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->win, res->txt[exits],
					x * RES_MULTIPLIER, y * RES_MULTIPLIER);
		}
	}
}
