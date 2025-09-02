/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:47 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/02 14:49:52 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


t_point	find_player(char **matrix)
{
	t_point pos;

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
	return (t_point){-1, -1};
}

