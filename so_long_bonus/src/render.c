/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:07:24 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 15:04:43 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	init_map(t_vars *vars)
{
	int	y;
	int	x;
	int	i;
	int	idx;

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
			{
				mlx_image_to_window(vars->mlx, vars->collect_imgs[0], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(vars->mlx, vars->collect_imgs[1], x * TILE_SIZE, y * TILE_SIZE);
				idx = vars->collect_imgs[0]->count - 1;
				vars->collect_imgs[0]->instances[idx].enabled = true;
				vars->collect_imgs[1]->instances[idx].enabled = false;
				vars->collect_anim_frame = 0;
			}
			else if (vars->map[y][x] == 'E')
			{
				mlx_image_to_window(vars->mlx, vars->exit_imgs[0], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(vars->mlx, vars->exit_imgs[1], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(vars->mlx, vars->exit_imgs[2], x * TILE_SIZE, y * TILE_SIZE);
				vars->exit_imgs[0]->instances[0].enabled = true;
				vars->exit_imgs[1]->instances[0].enabled = false;
				vars->exit_imgs[2]->instances[0].enabled = false;
				vars->exit_anim_frame = 0;
			}
			x++;
		}
		y++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(vars->mlx, vars->player.imgs[i], vars->player.pos.x * TILE_SIZE, vars->player.pos.y * TILE_SIZE);
		vars->player.imgs[i]->instances[0].enabled = (i == 0);
		i++;
	}
}

void	render_map(t_vars *vars)
{
	uint32_t	i;
	int			base;
	int			base2;

	i = 0;
	base = (vars->player.player_dir == 0) ? 0 : 3;
	while (i < 3)
	{
		vars->player.imgs[base + i]->instances[0].x = vars->player.pos.x * TILE_SIZE;
		vars->player.imgs[base + i]->instances[0].y = vars->player.pos.y * TILE_SIZE;
		vars->player.imgs[base + i]->instances[0].enabled = (i == (uint32_t)vars->player.anim_state);
		i++;
	}
	base2 = (vars->player.player_dir == 0) ? 3 : 0;
	i = 0;
	while (i < 3)
	{
		vars->player.imgs[base2 + i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < vars->collect_imgs[0]->count)
	{
		if ((vars->collect_imgs[0]->instances[i].x == vars->player.pos.x * TILE_SIZE) &&
			(vars->collect_imgs[0]->instances[i].y == vars->player.pos.y * TILE_SIZE))
		{
			vars->collect_imgs[0]->instances[i].enabled = false;
			vars->collect_imgs[1]->instances[i].enabled = false;
		}
		i++;
	}
}
