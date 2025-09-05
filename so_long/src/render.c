/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:07:24 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/05 19:37:12 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_render(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			mlx_image_to_window(vars->mlx, vars->floor_img, x * TILE_SIZE, y * TILE_SIZE);
			if (vars->map[y][x] == '1')
				mlx_image_to_window(vars->mlx, vars->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (vars->map[y][x] == 'C')
				mlx_image_to_window(vars->mlx, vars->collect_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (vars->map[y][x] == 'E')
				mlx_image_to_window(vars->mlx, vars->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(vars->mlx, vars->player.img, vars->player.pos.x * TILE_SIZE, vars->player.pos.y * TILE_SIZE);
}

void	render_map(t_vars *vars)
{
	
}
