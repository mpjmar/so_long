/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:17:59 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/13 15:04:27 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_borders(char **matrix)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	j = 0;
	height = get_height(matrix);
	while (matrix[0][i])
	{
		if (matrix[0][i] == '1' && matrix[height - 1][i] == '1')
			i++;
		else
			ft_error(6);
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

int	read_map(char **matrix, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	count_elements(char **matrix)
{
	int	e;
	int	p;
	int	c;

	e = read_map(matrix, 'E');
	p = read_map(matrix, 'P');
	c = read_map(matrix, 'C');
	if (e != 1)
		ft_error(7);
	if (p != 1)
		ft_error(8);
	if (c < 1)
		ft_error(9);
	return (0);
}

int	check_valid_chars(char *map_str)
{
	while (*map_str)
	{
		if (*map_str == '1' || *map_str == '0'
			|| *map_str == 'E' || *map_str == 'P'
			|| *map_str == 'C' || *map_str == '\n'
			|| *map_str == '\0')
			map_str++;
		else
			ft_error(5);
	}
	return (0);
}

int	check_empty_line(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] && map_str[i + 1])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			ft_error(5);
		i++;
	}
	return (0);
}
