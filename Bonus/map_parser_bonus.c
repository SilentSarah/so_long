/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:40:38 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/18 19:20:53 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_extension(char *map_name, t_data *tools)
{
	int	i;

	i = ft_strlen(map_name) - 1;
	ft_printf("[❗]Checking Map Extension...\n");
	if (map_name[i] != 'r' || map_name[i - 1] != 'e' || map_name[i - 2] != 'b'
		|| map_name[i - 3] != '.')
		print_error(0, tools);
	ft_printf("[✅]Map extension ends with .ber\n");
}

void	check_map_elements(t_data *tools, t_map *map_data, t_mlx *mlx)
{
	ft_printf("[❗]Checking Map Elements...\n");
	analyse_map(tools, map_data);
	if ((map_data->coins <= 0 || map_data->players < 1 || map_data->exits < 1)
		|| map_data->players > 1 || map_data->exits > 1)
		print_error(2, tools);
	if (map_data->enemies <= 0)
		ft_printf("[❗]WARNING: Map has no enemy placements!\n");
	mlx->map_data = map_data;
	check_map_dimensions(tools);
}

void	check_map_dimensions(t_data *tools)
{
	int	first_len;
	int	i;

	i = -1;
	first_len = (int)ft_strlen(tools->matrix[0]);
	while (++i < tools->height)
		if (first_len != (int)ft_strlen(tools->matrix[i]))
			print_error(2, tools);
	tools->length = ft_strlen(tools->matrix[0]);
	check_map_walls(tools);
}

void	check_map_validity(t_data *tools)
{
	char	**test_map;
	bool	elements_left;

	ft_printf("[❗]Finding a valid path in the map...\n");
	test_map = clone_map(tools);
	find_player_pos(tools);
	flood_map(tools->x, tools->y, test_map, tools);
	elements_left = check_remaining_items(test_map, tools);
	if (elements_left)
	{
		free_2d_arr(test_map, tools->height);
		print_error(3, tools);
	}
	free_2d_arr(test_map, tools->height);
	check_textures(tools);
}

void	check_map_walls(t_data *tools)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (tools->matrix[i][++j])
	{
		if (tools->matrix[i][j] != '1'
		|| tools->matrix[tools->height - 1][j] != '1')
			print_error(2, tools);
	}
	i = 0;
	j = (int)ft_strlen(tools->matrix[0]) - 1;
	while (i < tools->height)
	{
		if (tools->matrix[i][0] != '1'
		|| tools->matrix[i][j] != '1')
			print_error(2, tools);
		i++;
	}
	ft_printf("[✅]All map elements are in place.\n");
	check_map_validity(tools);
}
