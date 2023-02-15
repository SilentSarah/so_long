/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_to_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:09:18 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/14 13:17:20 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_bot_left(t_data *tools)
{
	find_enemy_pos(tools);
	find_player_pos(tools);
	if (tools->matrix[tools->e_y][tools->e_x + 1] != 'C'
		&& tools->matrix[tools->e_y][tools->e_x + 1] != '1'
		&& tools->matrix[tools->e_y][tools->e_x + 1] != 'E'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != 'X')
	{
		tools->matrix[tools->e_y][++tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
}

void	move_bot_right(t_data *tools)
{
	find_enemy_pos(tools);
	find_player_pos(tools);
	if (tools->matrix[tools->e_y][tools->e_x - 1] != 'C'
		&& tools->matrix[tools->e_y][tools->e_x - 1] != '1'
		&& tools->matrix[tools->e_y][tools->e_x - 1] != 'E'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != 'X')
	{
		tools->matrix[tools->e_y][--tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
}

void	move_bot_up(t_data *tools)
{
	find_enemy_pos(tools);
	find_player_pos(tools);
	if (tools->matrix[tools->e_y - 1][tools->e_x] != 'C'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != '1'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != 'E'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != 'X')
	{
		tools->matrix[--tools->e_y][tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
}

void	move_bot_down(t_data *tools)
{
	find_enemy_pos(tools);
	find_player_pos(tools);
	if (tools->matrix[tools->e_y + 1][tools->e_x] != 'C'
		&& tools->matrix[tools->e_y + 1][tools->e_x] != '1'
		&& tools->matrix[tools->e_y + 1][tools->e_x] != 'E'
		&& tools->matrix[tools->e_y + 1][tools->e_x] != 'X')
	{
		tools->matrix[++tools->e_y][tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
}
