/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:47 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/12 19:34:51 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_point	find_player(char **matrix)
{
	t_point	pos;

	pos.y = 0;
	while (matrix[pos.y])
	{
		pos.x = 0;
		while (matrix[pos.y][pos.x])
		{
			if (matrix[pos.y][pos.x] == 'P')
				return (pos);
			else
				pos.x++;
		}
		pos.y++;
	}
	return ((t_point){-1, -1});
}

t_point	find_exit(char **matrix)
{
	t_point	pos;

	pos.y = 0;
	while (matrix[pos.y])
	{
		pos.x = 0;
		while (matrix[pos.y][pos.x])
		{
			if (matrix[pos.y][pos.x] == 'E')
				return (pos);
			else
				pos.x++;
		}
		pos.y++;
	}
	return ((t_point){-1, -1});
}

int	items_count(t_vars *vars)
{
	int		y;
	int		x;
	int		count;
	char	**matrix;

	y = 0;
	count = 0;
	matrix = vars->map;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

mlx_t	*init_game(char **map)
{
	int		width;
	int		height;
	mlx_t	*mlx;

	width = get_width(map) * TILE_SIZE;
	height = get_height(map) * TILE_SIZE;
	mlx = mlx_init(width, height, "so_long", true);
	return (mlx);
}

void	init_vars(t_vars *vars, mlx_t *mlx, char **map)
{
	mlx_texture_t	*tex;
	mlx_texture_t	*tex1;
	mlx_texture_t	*tex2;
	mlx_texture_t	*tex3;
	mlx_texture_t	*tex4;
	mlx_texture_t	*tex5;
	mlx_texture_t	*tex6;

	vars->mlx = mlx;
	vars->map = map;
	vars->items = items_count(vars);
	vars->moves = 0;
	vars->exit = find_exit(map);
	vars->player.pos = find_player(map);
	vars->player.next_pos = vars->player.pos;
	vars->player.moves = 0;
	tex1 = mlx_load_png("resources/sprites/player_1_right.png");
	tex2 = mlx_load_png("resources/sprites/player_2_right.png");
	tex3 = mlx_load_png("resources/sprites/player_3_right.png");
	tex4 = mlx_load_png("resources/sprites/player_1_left.png");
	tex5 = mlx_load_png("resources/sprites/player_2_left.png");
	tex6 = mlx_load_png("resources/sprites/player_3_left.png");
	vars->player.imgs[0] = mlx_texture_to_image(mlx, tex1);
	vars->player.imgs[1] = mlx_texture_to_image(mlx, tex2);
	vars->player.imgs[2] = mlx_texture_to_image(mlx, tex3);
	vars->player.imgs[3] = mlx_texture_to_image(mlx, tex4);
	vars->player.imgs[4] = mlx_texture_to_image(mlx, tex5);
	vars->player.imgs[5] = mlx_texture_to_image(mlx, tex6);
	mlx_delete_texture(tex1);
	mlx_delete_texture(tex2);
	mlx_delete_texture(tex3);
	mlx_delete_texture(tex4);
	mlx_delete_texture(tex5);
	mlx_delete_texture(tex6);
	vars->player.player_dir = 0;
	vars->player.anim_state = 0;
	vars->player.anim_timer = 0;
	tex = mlx_load_png("resources/sprites/wall.png");
	vars->wall_img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	tex = mlx_load_png("resources/sprites/floor.png");
	vars->floor_img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	tex1 = mlx_load_png("resources/sprites/collect_2.png");
	tex2 = mlx_load_png("resources/sprites/collect_3.png");
	vars->collect_imgs[0] = mlx_texture_to_image(mlx, tex1);
	vars->collect_imgs[1] = mlx_texture_to_image(mlx, tex2);
	mlx_delete_texture(tex1);
	mlx_delete_texture(tex2);
	tex1 = mlx_load_png("resources/sprites/exit1.png");
	tex2 = mlx_load_png("resources/sprites/exit2.png");
	tex3 = mlx_load_png("resources/sprites/exit3.png");
	vars->exit_imgs[0] = mlx_texture_to_image(vars->mlx, tex1);
	vars->exit_imgs[1] = mlx_texture_to_image(vars->mlx, tex2);
	vars->exit_imgs[2] = mlx_texture_to_image(vars->mlx, tex3);
	mlx_delete_texture(tex1);
	mlx_delete_texture(tex2);
	mlx_delete_texture(tex3);
}

void	loop_handler(void *param)
{
	t_vars		*vars;
	uint32_t	i;
	static int	frame = 0;
	static int	anim = 0;

	vars = (t_vars *)param;
	frame++;
	if (frame >= 60)
	{
		vars->exit_imgs[anim]->instances[0].enabled = false;
		anim = (anim + 1) % 3;
		vars->exit_imgs[anim]->instances[0].enabled = true;
		i = 0;
		while (i < vars->collect_imgs[0]->count)
		{
			if (vars->collect_imgs[0]->instances[i].enabled ||
				vars->collect_imgs[1]->instances[i].enabled)
			{
				vars->collect_imgs[0]->instances[i].enabled = 
				!vars->collect_imgs[0]->instances[i].enabled;
				vars->collect_imgs[1]->instances[i].enabled =
				!vars->collect_imgs[1]->instances[i].enabled;
			}
			i++;
		}
		frame = 0;
	}
	if (vars->player.anim_state > 0)
	{
		vars->player.anim_timer++;
		if (vars->player.anim_state == 1 && vars->player.anim_timer > 10)
		{
			vars->player.anim_state = 2;
			vars->player.anim_timer = 0;
		}
	}
}
