/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:54 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/09 19:44:04 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			update_player_pos(vars, 'R');
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			update_player_pos(vars, 'L');
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			update_player_pos(vars, 'U');
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			update_player_pos(vars, 'D');
		else
			ft_printf("Invalid key\n");
	}
}

void update_player_pos(t_vars *vars, char mov)
{
	vars->player.next_pos.x = vars->player.pos.x;
	vars->player.next_pos.y = vars->player.pos.y;
	if (mov == 'R')
		vars->player.next_pos.x++;
	else if (mov == 'L')
		vars->player.next_pos.x--;
	else if (mov == 'U')
		vars->player.next_pos.y--;
	else if (mov == 'D')
		vars->player.next_pos.y++;
}

void	modify_map(t_vars *vars)
{
	int	old_y;
	int	old_x;
	int	new_y;
	int	new_x;

	old_y = vars->player.pos.y;
	old_x = vars->player.pos.x;
	new_y = vars->player.next_pos.y;
	new_x = vars->player.next_pos.x;
	if (vars->map[new_y][new_x] == '1')
		return ;
	if (vars->map[new_y][new_x] == 'C')
		vars->items -= 1;
	vars->map[new_y][new_x] = 'P';
	if (vars->exit.y == old_y && vars->exit.x == old_x)
		vars->map[old_y][old_x] = 'E';
	else
		vars->map[old_y][old_x] = '0';
	vars->moves += 1;
	ft_printf("Number of moves: %d\n", vars->moves);
	vars->player.pos = vars->player.next_pos;
	if (vars->map[new_y][new_x] == 'E' && vars->items == 0)
		close_handler(vars);
	render_map(vars);
}

void	close_handler(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_matrix(vars->map);
	mlx_terminate(vars->mlx);
	exit(0);
}
