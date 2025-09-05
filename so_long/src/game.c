/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:47 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/05 19:06:50 by maria-j2         ###   ########.fr       */
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

int	items_count(char **matrix)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'C');
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
	mlx_texture_t	*texture;

	vars->mlx = mlx;
	vars->map = map;
	vars->items = items_count(map);
	vars->player.pos = find_player(map);
	vars->player.moves = 0;
	vars->player.collected = 0;
	/* vars->player.img = mlx_texture_to_image(mlx, mlx_load_png("resources/sprites/player_img.png"));
	vars->wall_img = mlx_texture_to_image(mlx, mlx_load_png("resources/sprites/wall_img.png"));
	vars->floor_img = mlx_texture_to_image(mlx, mlx_load_png("resources/sprites/floor_img.png"));
	vars->collect_img = mlx_texture_to_image(mlx, mlx_load_png("resources/sprites/collect_img.png"));
	vars->exit_img = mlx_texture_to_image(mlx, mlx_load_png("resources/sprites/exit_img.png")); */
	
	texture = mlx_load_png("resources/sprites/player_img.png");
	if (!texture)
		ft_printf("Fail to load player_img.png");
	vars->player.img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	
	texture = mlx_load_png("resources/sprites/wall_img.png");
	if (!texture)
		ft_printf("Fail to load wall_img.png");
	vars->wall_img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("resources/sprites/floor_img.png");
	if (!texture)
		ft_printf("Fail to load wall_img.png");
	vars->floor_img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("resources/sprites/collect_img.png");
	if (!texture)
		ft_printf("Fail to load collect_img.png");
	vars->collect_img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("resources/sprites/exit_img.png");
	if (!texture)
		ft_printf("Fail to load exit_img.png");
	vars->exit_img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
}

void	loop_handler(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	
	render_map(vars);
}
