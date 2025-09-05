/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:54 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/04 17:06:54 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_D)
		vars->player.pos.x += 1;
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_A)
		vars->player.pos.x -= 1;
	else if (keycode == KEY_ARROW_UP || keycode == KEY_W)
		vars->player.pos.y -= 1;
	else if (keycode == KEY_ARROW_DOWN || keycode == KEY_S)
		vars->player.pos.y += 1;
	return (0);
}

void	close_handler(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_matrix(vars->map);
	mlx_terminate(vars->mlx);
	exit(0);
}
