/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:45:18 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/03 18:23:27 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	mlx_t	*mlx;
	int		width;
	int		height;

	map = NULL;
	if (argc != 2)
		ft_error(0);
	if (!map_validation(argv[1]))
		map = fill_map(read_map_file(argv[1]));
	else
		return (1);
	width = get_width(map) * TILE_SIZE;
	height = get_height(map) * TILE_SIZE;
	mlx = mlx_init(width, height, "so_long", true);
	if (!mlx)
		return (1);
	mlx_loop(mlx);
	free_matrix(map);
	mlx_terminate(mlx);
	return (0);
}
