/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:39:06 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/15 10:52:52 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_game(t_textures *res)
{
	int	i;

	i = -1;
	ft_printf("[❗]Destorying Resources...\n");
	while (++i < 35)
	{
		ft_printf("[❗]Destroying Resource ID: %d\n", i);
		mlx_destroy_image(res->mlx_data->init, res->txt[i]);
	}
	mlx_destroy_window(res->mlx_data->init, res->mlx_data->win);
	ft_printf("[❗]Exiting the game...\n");
	free(res->mlx_data->init);
	free_2d_arr(res->utils->matrix, res->utils->height);
	exit(0);
	return (0);
}

void	enemy_reaction(t_textures *res)
{
	t_map		*map_data;

	map_data = res->mlx_data->map_data;
	find_player_pos(res->utils);
	if (map_data->damage < 2)
		health_system_check(res);
	else
	{
		map_data->damage = 2;
		map_data->players = 0;
		ft_printf("[❌]You lost, Game Over!\n");
		mlx_clear_window(res->mlx_data->init, res->mlx_data->win);
		display_game_over_screen(res);
	}
}

bool	map_env_scan(int x, int y, t_textures *res)
{
	if (res->utils->matrix[y][x] != '1')
	{
		if (res->utils->matrix[y][x] == 'C')
		{
			res->utils->matrix[y][x] = 'P';
			res->mlx_data->map_data->coins--;
		}
		else if (res->utils->matrix[y][x] == '0')
			res->utils->matrix[y][x] = 'P';
		if (res->mlx_data->map_data->coins == 0)
		{
			if (res->utils->matrix[y][x] == 'E')
			{
				ft_printf("[✅]Congratulations, You win!\n");
				destroy_game(res);
			}
		}
		else
			if (res->utils->matrix[y][x] == 'E')
				return (false);
		return (true);
	}
	return (false);
}

bool	move_player(int direction, t_textures *res)
{
	if (direction == up)
		return (map_env_scan(res->utils->x, res->utils->y - 1, res));
	else if (direction == left)
		return (map_env_scan(res->utils->x - 1, res->utils->y, res));
	else if (direction == down)
		return (map_env_scan(res->utils->x, res->utils->y + 1, res));
	else if (direction == right)
		return (map_env_scan(res->utils->x + 1, res->utils->y, res));
	return (false);
}

int	key_response(int key_press, t_textures *res)
{
	if (res->mlx_data->map_data->players == 1)
	{
		find_player_pos(res->utils);
		if (move_player(key_press, res))
		{
			res->utils->matrix[res->utils->oldpos[0]]
			[res->utils->oldpos[1]] = '0';
			++res->mlx_data->map_data->s_moves;
		}
	}
	if (key_press == 53)
		destroy_game(res);
	return (0);
}
