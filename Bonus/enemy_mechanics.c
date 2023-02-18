/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mechanics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:13:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/18 11:49:58 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spawn_new_enemy(t_data *tools)
{
	int	i;
	int	j;

	i = -1;
	while (tools->matrix[++i])
	{
		j = -1;
		while (tools->matrix[i][++j])
		{
			if (tools->matrix[i][j] == 'C')
			{
				if (tools->matrix[i][j + 1] == '0')
					tools->matrix[i][j + 1] = 'X';
				else if (tools->matrix[i][j - 1] == '0')
					tools->matrix[i][j - 1] = 'X';
				else if (tools->matrix[i + 1][j] == '0')
					tools->matrix[i + 1][j] = 'X';
				else if (tools->matrix[i - 1][j] == '0')
					tools->matrix[i - 1][j] = 'X';
				return ;
			}
		}
	}
}

void	health_system_check(t_textures *res)
{
	t_map	*map_data;

	map_data = res->mlx_data->map_data;
	map_data->damage++;
	map_data->enemies--;
	find_enemy_pos(res->utils);
	find_player_pos(res->utils);
	res->utils->matrix[res->utils->y][res->utils->x] = 'P';
	mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
		res->txt[explosion], res->utils->x * 64, res->utils->y * 64);
	if (map_data->coins > 0)
	{
		spawn_new_enemy(res->utils);
		res->mlx_data->map_data->enemies++;
	}
	if (map_data->coins == 0)
	{
		map_data->damage = 2;
		map_data->players = 0;
		display_game_over_screen(res);
	}
}

void	display_game_over_screen(t_textures *res)
{
	mlx_clear_window(res->mlx_data->init, res->mlx_data->win);
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		(res->utils->length * 28), (res->utils->height * 48),
		get_color(255, 255, 255, 255), "Press ESC to end the game.");
	mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
		res->txt[34], (res->utils->length * 26), (res->utils->height * 40));
}

void	display_game_instructions(t_textures *res)
{
	res->mlx_data->map_data->players = 0;
	mlx_clear_window(res->mlx_data->init, res->mlx_data->win);
	mlx_put_image_to_window(res->mlx_data->init, res->mlx_data->win,
		res->txt[35], (res->utils->length * 28), (res->utils->height * 39));
	mlx_string_put(res->mlx_data->init, res->mlx_data->win,
		(res->utils->length * 28), (res->utils->height * 48),
		get_color(255, 255, 255, 255), "Press ENTER to start the game.");
}
