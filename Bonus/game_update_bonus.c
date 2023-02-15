/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:17:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/15 16:49:11 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	refresh_sprites(t_textures *res, int x, int y)
{
	static int	pf_id;
	static int	ef_id;

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
			res->txt[player + pf_id++], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'E')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[exits], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	else if (res->utils->matrix[y][x] == 'X')
		mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
			res->txt[enemy + ef_id++], x * RES_MULTIPLIER, y * RES_MULTIPLIER);
	if (pf_id >= 9)
		pf_id = 0;
	if (ef_id >= 5)
		ef_id = 0;
}

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	display_counters(t_textures *res)
{
	char		*smoves;
	char		*coins;
	const int	white = get_color(128, 255, 255, 255);

	smoves = ft_itoa(res->mlx_data->map_data->s_moves);
	coins = ft_itoa(res->mlx_data->map_data->coins);
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		0, 0, white, "Successful Moves:");
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		128 + 44, 0, white, smoves);
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		0, 32, white, "Coins Left:");
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		112, 32, white, coins);
	mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
		res->txt[heart + res->mlx_data->map_data->damage],
		72, 56);
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		0, 64, get_color(128, 255, 0, 0), "Health:");
	free (smoves);
	free (coins);
}

int	render_frames(t_textures *res)
{
	static int	ticks;

	if (res->mlx_data->map_data->players == 1)
	{
		update_frames(res, &ticks);
		if (ticks % 2500 == 0)
			res->mlx_data->map_data->is_patrolling = bot_awareness(res);
		if (ticks % 3500 == 0)
			if (!res->mlx_data->map_data->is_patrolling)
				patrol_map(res, res->utils);
		ticks++;
	}
	return (0);
}
