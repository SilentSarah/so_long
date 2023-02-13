/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:40:40 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/11 16:53:16 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map_data;
	t_data	tools;

	if (argc != 2)
		return (0);
	initialize_data(&tools, &map_data);
	check_map_extension(argv[1], &tools);
	tools.matrix = extract_map(argv[1], &tools, open_map);
	check_map_elements(&tools, &map_data, &mlx);
	find_resolution(&tools, &mlx);
	initiate_window(&mlx, &tools);
	return (0);
}
