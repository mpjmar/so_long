/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:54 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/06 20:40:03 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) &&
		keydata.action == MLX_RELEASE)
		update_player_pos(vars, 1);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) &&
		keydata.action == MLX_RELEASE)
		update_player_pos(vars, 2);
		// vars->player.pos.x -= 1;
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) &&
		keydata.action == MLX_RELEASE)
		update_player_pos(vars, 3);
		// vars->player.pos.y -= 1;
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) &&
		keydata.action == MLX_RELEASE)
		update_player_pos(vars, 4);
		// vars->player.pos.y += 1;
	
}

void	update_player_pos(t_vars *vars, int mov)
{
	if (mov == 1)
		1º- comprobar que la posicion destino es != 1 y es la E y no quedan C
			2º- comprobar que la posicion abandonada no es la salida
			CAMBIAR CHARS EN LA MATRIZ e incrementar contador mov e imprimir por consola
			3º- dibujar el mapa (render_map(vars->map))
	
	else if (mov == 2)

	else if (mov == 3)

	else if (mov == 4)
	
	HACER FUNCIONES:
	/* if (vars->map[vars->player.pos.y][vars->player.pos.x] != '1')
		vars->player.pos.x += 1;
	if (vars->map[vars->player.pos.y][vars->player.pos.x] == 'C')
		vars->player.collected += 1;
	if (vars->player.collected == vars->items && 
		vars->map[vars->player.pos.y][vars->player.pos.x] == 'E')
		mlx_close_hook o close_handler?? */
}

void	close_handler(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_matrix(vars->map);
	mlx_terminate(vars->mlx);
	exit(0);
}
