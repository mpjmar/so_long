/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:45:18 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/02 20:15:06 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc != 2)
		ft_error(0);
	if (!map_validation(argv[1]))
		map = fill_map(read_map_file(argv[1]));
	
	free_matrix(map);
	return (0);
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
		ft_printf("Error: invalid....\n");
	exit(EXIT_FAILURE); 
}
