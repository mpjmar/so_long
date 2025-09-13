/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:07:24 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 17:10:57 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			mlx_image_to_window(vars->mlx, vars->floor_img, x * SIZE, y * SIZE);
			if (vars->map[y][x] == '1')
				mlx_image_to_window(vars->mlx, vars->wall_img,
					x * SIZE, y * SIZE);
			else if (vars->map[y][x] == 'C')
				mlx_image_to_window(vars->mlx, vars->collect_img,
					x * SIZE, y * SIZE);
			else if (vars->map[y][x] == 'E')
				mlx_image_to_window(vars->mlx, vars->exit_img,
					x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(vars->mlx, vars->player.img, vars->player.pos.x * SIZE,
		vars->player.pos.y * SIZE);
}

void	loop_handler(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
}

void	render_map(t_vars *vars)
{
	uint32_t	i;

	i = 0;
	vars->player.img->instances[0].x = vars->player.pos.x * SIZE;
	vars->player.img->instances[0].y = vars->player.pos.y * SIZE;
	while (i < vars->collect_img->count)
	{
		if ((vars->collect_img->instances[i].x == vars->player.pos.x * SIZE)
			&& (vars->collect_img->instances[i].y == vars->player.pos.y * SIZE))
			vars->collect_img->instances[i].enabled = false;
		i++;
	}
}
