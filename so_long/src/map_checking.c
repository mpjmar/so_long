/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:17:59 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/31 18:05:05 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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

int	check_elements(char **matrix)
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

int	check_valid_chars(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1' || matrix[i][j] == '0' || 
				matrix[i][j] == 'E' || matrix[i][j] == 'P' || 
				matrix[i][j] == 'C' )
				j++;
			else
				ft_error(10);
		}
		i++;
	}
	return (0);
}
