/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:45:18 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 16:51:39 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	char	*map_str;
	char	**map;
	mlx_t	*mlx;

	map = NULL;
	if (argc != 2)
		ft_error(0);
	if (!map_validation(argv[1]))
	{
		map_str = read_map_file(argv[1]);
		map = fill_map(map_str);
		free(map_str);
	}
	else
		return (1);
	mlx = init_game(map);
	if (!mlx)
		return (1);
	play_game(mlx, map);
	return (0);
}

void	play_game(mlx_t *mlx, char **map)
{
	t_vars	vars;

	init_vars(&vars, mlx, map);
	init_map(&vars);
	mlx_loop_hook(vars.mlx, loop_handler, &vars);
	mlx_key_hook(vars.mlx, key_handler, &vars);
	mlx_close_hook(vars.mlx, close_handler, &vars);
	mlx_loop(vars.mlx);
	free_matrix(map);
	mlx_terminate(vars.mlx);
}
