/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:50 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/29 19:24:13 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**dup_map(char **matrix)
{
	char	**dup_map;
	int		i;
	int		j;

	dup_map = malloc();
	i = 0;
	while (matrix[i])
	{
		ft_strdup(matrix[i]);
		i++;
	}
	matrix[i] = NULL;
	return (dup_map);
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
