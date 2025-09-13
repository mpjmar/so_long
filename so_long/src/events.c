/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:54 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/12 17:48:28 by maria-j2         ###   ########.fr       */
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
			move_player(vars, 'R');
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			move_player(vars, 'L');
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			move_player(vars, 'U');
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			move_player(vars, 'D');
		else if (keydata.key == MLX_KEY_ESCAPE)
			close_handler(vars);
		else
			ft_printf("Invalid key\n");
	}
}

void update_player_pos(t_vars *vars, char mov)
{
	vars->player.next_pos = vars->player.pos;
	if (mov == 'R')
		vars->player.next_pos.x++;
	else if (mov == 'L')
		vars->player.next_pos.x--;
	else if (mov == 'U')
		vars->player.next_pos.y--;
	else if (mov == 'D')
		vars->player.next_pos.y++;
}

void	move_player(t_vars *vars, char mov)
{
	update_player_pos(vars, mov);
	int	new_y;
	int	new_x;

	new_y = vars->player.next_pos.y;
	new_x = vars->player.next_pos.x;
	if (vars->map[new_y][new_x] == '1')
		return ;
	vars->player.pos = vars->player.next_pos;
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->items -= 1;
		vars->map[new_y][new_x] = '0';
	}
	vars->moves += 1;
	ft_printf("Number of moves: %d\n", vars->moves);
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
