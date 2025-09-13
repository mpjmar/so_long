/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:38:16 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 15:07:20 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*read_map_file(char *map_name)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	*tmp;

	map_str = ft_strdup("");
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	line = get_next_line(fd);
	if (ft_strlen(line) > 0)
	{
		while (line != NULL)
		{
			tmp = map_str;
			map_str = ft_strjoin(map_str, line);
			free(tmp);
			free(line);
			line = get_next_line(fd);
		}
	}
	else
		free(line);
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
	return (map);
}

t_point	get_size(char **matrix)
{
	t_point	size;

	size.x = get_width(matrix);
	size.y = get_height(matrix);
	return (size);
}
