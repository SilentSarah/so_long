/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:42:06 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/10 12:28:45 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name, t_data *tools)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		print_error(1, tools);
	return (fd);
}

char	**extract_map(char *map_name, t_data *tools, int (*f)(char *, t_data *))
{
	char	t_string[MAX_MAP_SIZE];
	char	**matrix;

	read(f(map_name, tools), t_string, MAX_MAP_SIZE);
	matrix = ft_split(t_string, '\n');
	tools->height = (int)countdelims(t_string, '\n');
	tools->length = (int)ft_strlen(matrix[0]);
	return (matrix);
}

char	**clone_map(t_data *tools)
{
	int		i;
	char	**test_map;

	i = -1;
	test_map = (char **)malloc(sizeof(char *) * tools->height);
	if (!test_map)
		free_2d_arr(tools->matrix, tools->height);
	while (++i < tools->height)
	{
		test_map[i] = ft_strdup(tools->matrix[i]);
		if (!test_map[i])
		{
			free_2d_arr(tools->matrix, tools->height);
			free(test_map);
			write(2, "[❌]Error: Cannot load the test map into memory.\n", 52);
			exit(1);
		}
	}
	test_map[i] = NULL;
	return (test_map);
}

void	find_player_pos(t_data *tools)
{
	int	x;
	int	y;

	y = -1;
	while (++y < tools->height)
	{
		x = -1;
		while (tools->matrix[y][++x])
		{
			if (tools->matrix[y][x] == 'P')
			{
				tools->x = x;
				tools->y = y;
				tools->oldpos[0] = y;
				tools->oldpos[1] = x;
				return ;
			}
		}
	}
	return ;
}

void	flood_map(int x, int y, char **map, t_data *tools)
{
	if ((x >= tools->length) || (y >= tools->height)
		|| (x <= 0) || (y <= 0) || (map[y][x] == '1'))
		return ;
	map[y][x] = '1';
	flood_map(x + 1, y, map, tools);
	flood_map(x - 1, y, map, tools);
	flood_map(x, y + 1, map, tools);
	flood_map(x, y - 1, map, tools);
	return ;
}
