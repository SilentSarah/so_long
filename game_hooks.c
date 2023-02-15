/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:49:21 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/10 15:22:23 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_game(t_textures *res)
{
	int	i;

	i = -1;
	ft_printf("[❗]Destorying Resources...\n");
	while (++i < 5)
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
	static int	successful_moves;

	find_player_pos(res->utils);
	if (move_player(key_press, res))
	{
		res->utils->matrix[res->utils->oldpos[0]][res->utils->oldpos[1]] = '0';
		ft_printf("Successful Move N:%d\n", ++successful_moves);
	}
	if (key_press == 53)
		destroy_game(res);
	display_map_elements(res->utils, res->mlx_data, res);
	return (0);
}
