/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:38:16 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/29 18:46:25 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*read_map_file(char *map_name)
{
	int		fd;
	char	*line;
	char	*map_str;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_str = ft_strjoin(map_str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_str);
}

char	**fill_map(char *map_str)
{
	char	**map;
	int		i;
	
	i = 0;
	map = ft_split(map_str);
	if (!map)
	{
		free(map_str);
		free_matrix(map);
		ft_error(3);
	}
	free(map_str);
	return (map);
}

void	init_map(t_point size) // TERMINAR!!
{
	size.x = 0;
	size.y = 0;
}

int	get_width(t_point *size, char **matrix)
{
	int	width;

	width = 0;
	while (matrix[0][width])
		width++;
	size->x = width;
	return (width);
}

int	get_height(t_point *size, char **matrix)
{
	int	height;

	height = 0;
	while (matrix[height][0])
		height++;
	size->y = height;
	return (height);
}
