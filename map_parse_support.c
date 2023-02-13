/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:07:26 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/11 16:50:14 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	analyse_map(t_data *tools, t_map *map_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tools->height)
	{
		j = -1;
		while (tools->matrix[i][++j])
		{
			if (tools->matrix[i][j] == 'E')
				map_data->exits += 1;
			else if (tools->matrix[i][j] == 'P')
				map_data->players += 1;
			else if (tools->matrix[i][j] == 'C')
				map_data->coins += 1;
			else if (tools->matrix[i][j] == 'X')
				map_data->enemies += 1;
			else if (!ft_strchr("EP1CX0", tools->matrix[i][j]))
				map_data->rdata = 1;
		}
	}
}
