/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:42 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/30 20:05:23 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_validation(char *map_name)
{
	char	**matrix;

	map_ext(map_name);
	matrix = fill_map(read_map_file(map_name));
	is_rectangle(matrix);
	check_borders(matrix);
	check_chars(matrix);
	check_elements(matrix);
	check_path(matrix);
	return (0);
}

int	map_ext(char *map_name)
{
	char	*ext;
	int		len;

	ext = ".ber";
	len = ft_strlen(map_name);
	if (map_name && ft_strncmp(map_name[len], ext, 4) == 0)
		len -= 4;
	else
		ft_error(1);
	return (0);
}

int	is_rectangle(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i + 1])
	{
		if (ft_strlen(matrix[i]) == ft_strlen(matrix[i + 1]))
			i++;
		else
			ft_error(4);
	}
	return (0);
}

void	flood_fill(char **matrix, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| matrix[cur.y][cur.x] != to_fill)
		ft_print(7);
	matrix[cur.y][cur.x] = '#';
	flood_fill(matrix, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(matrix, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(matrix, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(matrix, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

int	check_path(char **map)
{
	
	return (0);
}
