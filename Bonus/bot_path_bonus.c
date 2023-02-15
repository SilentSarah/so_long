/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:49:48 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/15 16:49:51 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy_pos(t_data *tools)
{
	int	y;
	int	x;

	y = -1;
	while (tools->matrix[++y])
	{
		x = -1;
		while (tools->matrix[y][++x])
		{
			if (tools->matrix[y][x] == 'X')
			{
				tools->e_y = y;
				tools->e_x = x;
				tools->e_oldpos[0] = y;
				tools->e_oldpos[1] = x;
			}
		}
	}
}

bool	check_if_player_near_enemy(t_textures *res)
{
	find_enemy_pos(res->utils);
	find_player_pos(res->utils);
	if (res->utils->x >= res->utils->e_x - 6
		&& res->utils->x <= res->utils->e_x + 6
		&& res->utils->y <= res->utils->e_y + 7
		&& res->utils->y >= res->utils->e_y - 7)
		return (true);
	return (false);
}

void	move_enemy_to_player(t_textures *res, t_data *tools)
{
	if (tools->x > tools->e_x)
		move_bot_left(tools);
	else if (tools->x < tools->e_x)
		move_bot_right(tools);
	else if (tools->y < tools->e_y)
		move_bot_up(tools);
	else if (tools->y > tools->e_y)
		move_bot_down(tools);
	find_enemy_pos(tools);
	if (tools->x == tools->e_x && tools->y == tools->e_y
		&& tools->matrix[tools->e_y])
		enemy_reaction(res);
}

void	patrol_map(t_textures *res, t_data *tools)
{
	static bool	is_p_near = false;
	int			rng;

	if (res->mlx_data->map_data->enemies > 0)
	{
		rng = arc4random_uniform(100);
		is_p_near = check_if_player_near_enemy(res);
		if (is_p_near)
			move_enemy_to_player(res, res->utils);
		else
		{
			if (rng <= 12)
				move_bot_left(tools);
			else if (rng >= 13 && rng <= 50)
				move_bot_right(tools);
			else if (rng >= 51 && rng <= 63)
				move_bot_up(tools);
			else if (rng >= 64)
				move_bot_down(tools);
		}
		find_enemy_pos(tools);
	}
}

bool	bot_awareness(t_textures *res)
{
	if (res->mlx_data->map_data->enemies > 0)
	{
		res->mlx_data->map_data->is_patrolling
			= check_if_player_near_enemy(res);
		if (res->mlx_data->map_data->is_patrolling)
			move_enemy_to_player(res, res->utils);
	}
	return (false);
}
