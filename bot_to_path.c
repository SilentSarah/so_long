/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_to_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:09:18 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/12 20:07:25 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_bot_left(t_data *tools)
{
	if (tools->matrix[tools->e_y][tools->e_x + 1] != 'C'
		&& tools->matrix[tools->e_y][tools->e_x + 1] != '1'
		&& tools->matrix[tools->e_y][tools->e_x + 1] != 'E')
	{
		tools->matrix[tools->e_y][++tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
	else
	{
		if (tools->y < tools->e_y)
			move_bot_up(tools);
		else if (tools->y > tools->e_y)
			move_bot_down(tools);
	}
}

void	move_bot_right(t_data *tools)
{
	if (tools->matrix[tools->e_y][tools->e_x - 1] != 'C'
		&& tools->matrix[tools->e_y][tools->e_x - 1] != '1'
		&& tools->matrix[tools->e_y][tools->e_x - 1] != 'E')
	{
		tools->matrix[tools->e_y][--tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
	else
	{
		if (tools->y < tools->e_y)
			move_bot_up(tools);
		else if (tools->y > tools->e_y)
			move_bot_down(tools);
	}
}

void	move_bot_up(t_data *tools)
{
	if (tools->matrix[tools->e_y - 1][tools->e_x] != 'C'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != '1'
		&& tools->matrix[tools->e_y - 1][tools->e_x] != 'E')
	{
		tools->matrix[--tools->e_y][tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
	else
	{
		if (tools->x < tools->e_x)
			move_bot_left(tools);
		else if (tools->x > tools->e_x)
			move_bot_right(tools);
	}
}

void	move_bot_down(t_data *tools)
{
	if (tools->matrix[tools->e_y + 1][tools->e_x] != 'C'
		&& tools->matrix[tools->e_y + 1][tools->e_x] != '1'
		&& tools->matrix[tools->e_y + 1][tools->e_x] != 'E')
	{
		tools->matrix[++tools->e_y][tools->e_x] = 'X';
		tools->matrix[tools->e_oldpos[0]][tools->e_oldpos[1]] = '0';
	}
	else
	{
		if (tools->x < tools->e_x)
			move_bot_left(tools);
		else if (tools->x > tools->e_x)
			move_bot_right(tools);
	}
}
