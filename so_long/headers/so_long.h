/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:48:29 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/31 18:46:47 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>

/* typedef struct s_map
{
	int	width;
	int	height;
}		t_map; */

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// events


// free
void	free_matrix(char **matrix);

// game


// main
int		main(int argc, char **argv);
void	ft_error(int error);

// map_building
char	*read_map_file(char *map_name);
char	**fill_map(char *map_str);
void	init_map(t_point size);

// map_checking
int		check_borders(char **matrix);
int		read_map(char **matrix, char c);
int		check_elements(char **matrix);
int		check_valid_chars(char **matrix);

// map_validation
int		map_validation(char *map_name);
int		map_ext(const char *map_name);
int		is_rectangle(char **matrix);
void	flood_fill(char **matrix, t_point size, t_point cur, char to_fill);
int		check_path(char **map);

// render


// utils
char	**dup_map(char **matrix);
int		get_width(t_point *size, char **matrix);
int		get_height(t_point *size, char **matrix);
void	print_matrix(char **matrix);

# endif