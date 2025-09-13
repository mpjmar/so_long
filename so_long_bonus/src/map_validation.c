/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:42 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 15:06:39 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	map_validation(char *map_name)
{
	char	*map_str;
	char	**matrix;
	char	**matrix_dup;
	t_point	size;

	map_str = read_map_file(map_name);
	matrix = NULL;
	map_ext(map_name);
	check_valid_chars(map_str);
	check_empty_line(map_str);
	if (ft_strlen(map_str) == 0)
	{
		free(map_name);
		ft_error(5);
	}
	matrix = fill_map(map_str);
	free(map_str);
	matrix_dup = dup_map(matrix);
	is_rectangle(matrix);
	check_borders(matrix);
	count_elements(matrix);
	size = get_size(matrix);
	check_path(matrix_dup, size);
	free_matrix(matrix_dup);
	free_matrix(matrix);
	return (0);
}

int	map_ext(const char *map_name)
{
	char	*ext;
	int		len;

	if (map_name == NULL)
		ft_error(2);
	ext = ".ber";
	len = ft_strlen(map_name);
	if (!map_name || len < 5)
		ft_error(0);
	if (ft_strncmp(map_name + len - 4, ext, 4))
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

int	flood_fill(char **matrix_dup, t_point size, t_point pos)
{
	int	c_res;

	c_res = 0;
	if (pos.y < 0 || pos.y >= size.y || pos.x < 0 || pos.x >= size.x)
		return (1);
	if (matrix_dup[pos.y][pos.x] == '1' || matrix_dup[pos.y][pos.x] == '#')
		return (1);
	matrix_dup[pos.y][pos.x] = '#';
	flood_fill(matrix_dup, size, (t_point){pos.x - 1, pos.y});
	flood_fill(matrix_dup, size, (t_point){pos.x + 1, pos.y});
	flood_fill(matrix_dup, size, (t_point){pos.x, pos.y - 1});
	flood_fill(matrix_dup, size, (t_point){pos.x, pos.y + 1});
	if (read_map(matrix_dup, 'C') > 0 || read_map(matrix_dup, 'E') > 0)
		return (1);
	return (0);
}

int	check_path(char **matrix_dup, t_point size)
{
	t_point	pos;

	pos = find_player(matrix_dup);
	if (flood_fill(matrix_dup, size, pos))
		ft_error(5);
	return (0);
}
