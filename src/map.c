/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:06:42 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/26 18:22:22 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_validation(char *map)
{
	
	
}

int	map_ext(char *map)
{
	char	*ext;
	int		i;

	ext = ".ber";
	if (map && strlen(map) > 4)
	{
		while (map[i])
			i++;
		i -= 4;
	}
	else
		print_error(); // IMPLEMENTAR (free antes)!! perror, strerror, exit??? ¡¡¡investigar!!!
	if (!map ||ft_strncmp(map[i], ext, 4) != 0)
		return (1);
}

int	map_length(char *map)
{
	
}