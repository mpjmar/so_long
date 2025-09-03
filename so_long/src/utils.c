/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:50 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/03 19:50:38 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**dup_map(char **matrix)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	map_copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		map_copy[i] = ft_strdup(matrix[i]);
		if (!map_copy[i])
		{
			free_matrix(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	get_width(char **matrix)
{
	int	width;

	if (!matrix || !matrix[0])
		return (0);
	width = ft_strlen(matrix[0]);
	return (width);
}

int	get_height(char **matrix)
{
	int	height;

	height = 0;
	if (!matrix)
		return (0);
	while (matrix && matrix[height])
		height++;
	return (height);
}

void	print_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_error(int error)
{
	if (error == 0)
		ft_printf("Error: a proper map file must be provided as an argument");
	else if (error == 1)
		ft_printf("Error: map extension should be .ber\n");
	else if (error == 2)
		ft_printf("Error: failed to read the file\n");
	else if (error == 3)
		ft_printf("Error: failed to load the map\n");
	else if (error == 4)
		ft_printf("Error: the map is not a rectangle\n");
	else if (error == 5)
		ft_printf("Error: invalid map\n");
	else if (error == 6)
		ft_printf("Error: invalid borders\n");
	else if (error == 7)
		ft_printf("Error: invalid number of exits\n");
	else if (error == 8)
		ft_printf("Error: invalid number of players\n");
	else if (error == 9)
		ft_printf("Error: invalid number of collectibles\n");
	else if (error == 10)
		ft_printf("FOK\n");
	exit(EXIT_FAILURE);
}
