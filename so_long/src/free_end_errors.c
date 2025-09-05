/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:08:47 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/05 18:23:52 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
	exit(EXIT_FAILURE);
}
