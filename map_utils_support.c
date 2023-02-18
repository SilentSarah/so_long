/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:39:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/18 20:19:12 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_rdata_inside(char *raw_map, t_data *tools)
{
	int	i;

	i = -1;
	while (raw_map[++i])
	{
		if (raw_map[i] == '\n' && raw_map[i + 1] == '\n')
			print_error(2, tools);
	}
}

void	find_exit_pos(t_data *tools)
{
	int	y;
	int	x;

	y = -1;
	while (tools->matrix[++y])
	{
		x = -1;
		while (tools->matrix[y][++x])
		{
			if (tools->matrix[y][x] == 'E')
			{
				tools->ex = x;
				tools->ey = y;
				return ;
			}
		}
	}
}
