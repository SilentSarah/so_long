/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:39:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/15 12:44:27 by hmeftah          ###   ########.fr       */
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
