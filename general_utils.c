/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:42 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/18 19:25:24 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int id, t_data *tools)
{
	if (id == 0)
		write(2, INV_EXT, ft_strlen(INV_EXT));
	if (id == 1)
		write(2, OPN_ERR, ft_strlen(OPN_ERR));
	if (id == 2)
		write(2, EL_INV, ft_strlen(EL_INV));
	if (id == 3)
		write(2, PATH_ERR, ft_strlen(PATH_ERR));
	if (id == 4)
		write(2, TXT_ERR, ft_strlen(TXT_ERR));
	if (id == 5)
		write(2, RES_ERR, ft_strlen(RES_ERR));
	if (id == 2 || id == 3 || id == 4 || id == 5)
		free_2d_arr(tools->matrix, tools->height);
	exit (1);
}

void	free_2d_arr(char **matrix, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (matrix[i])
			free (matrix[i]);
	if (matrix)
		free (matrix);
}

void	initiate_window(t_mlx *mlx, t_data *tools)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		print_error(5, tools);
	mlx->win = mlx_new_window(mlx->init, mlx->w, mlx->h, "so_long <3");
	if (!mlx->win)
	{
		free(mlx->init);
		print_error(5, tools);
	}
	generate_map(tools, mlx);
	mlx_loop(mlx->init);
}

void	initialize_data(t_data *tools, t_map *map_data)
{
	tools->height = 0;
	tools->length = 0;
	tools->matrix = NULL;
	map_data->coins = 0;
	map_data->players = 0;
	map_data->exits = 0;
	tools->texit = false;
}

bool	check_remaining_items(char **test_map, t_data *tools)
{
	int	i;

	i = -1;
	find_exit_pos(tools);
	while (test_map[++i])
	{
		if (ft_strchr(test_map[i], 'C'))
			return (true);
		if (ft_strchr(test_map[i], 'E'))
		{
			if (!tools->texit)
				return (true);
		}
	}
	ft_printf("[???]Valid path has been found.\n");
	return (false);
}
