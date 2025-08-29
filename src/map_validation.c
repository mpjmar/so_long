/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:42 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/29 19:08:09 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_validation(char *map_name)
{
	char	**map;

	map_ext(map_name);
	map = fill_map(read_map_file(map_name));
	is_rectangle(map);
	check_borders(map);
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

int	is_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			ft_error(4);
	}
	return (0);
}

int	check_borders(char **matrix)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (matrix[0][i])
	{
		if (matrix[0][i] == '1')
			i++;
		else
			ft_error(5);
	}
	while (matrix[j])
	{
		if (matrix[j][0] == '1' && matrix[j][i - 1] == '1')
			j++;
		else
			ft_error(6);
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