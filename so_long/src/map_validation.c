/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:42 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/02 19:07:33 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_validation(char *map_name)
{
	char	**matrix;
	char	**matrix_dup;
	t_point	size;

	matrix = NULL;
	map_ext(map_name);
	if (!check_valid_chars(read_map_file(map_name)))
		matrix = fill_map(read_map_file(map_name));
	print_matrix(matrix);
	if (!matrix || !matrix[0] || !matrix[0][0])
		ft_error(3);
	matrix_dup = dup_map(matrix);
	is_rectangle(matrix);
	check_borders(matrix);
	count_elements(matrix);
	size = set_size(matrix);
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
	if (pos.y < 0 || pos.y >= size.y || pos.x < 0 || pos.x >= size.x)
		return (1);
	if (matrix_dup[pos.y][pos.x] == '1' || matrix_dup[pos.y][pos.x] == '#')
		return (1);
	matrix_dup[pos.y][pos.x] = '#';
	flood_fill(matrix_dup, size, (t_point){pos.x - 1, pos.y});
	flood_fill(matrix_dup, size, (t_point){pos.x + 1, pos.y});
	flood_fill(matrix_dup, size, (t_point){pos.x, pos.y - 1});
	flood_fill(matrix_dup, size, (t_point){pos.x, pos.y + 1});
	return (0);
}

int	check_path(char **matrix_dup, t_point size)
{
	t_point	pos;

	pos = find_player(matrix_dup);
	if (flood_fill(matrix_dup, size, pos))
		ft_error(10);
	return (0);
}
