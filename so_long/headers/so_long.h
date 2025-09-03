/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:48:29 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/03 17:59:35 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/MLX42.h"
# include <fcntl.h>
# include <errno.h>

# define TILE_SIZE 64

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// events


// free
void	free_matrix(char **matrix);

// game
t_point	find_player(char **matrix);

// main
int		main(int argc, char **argv);
void	ft_error(int error);

// map_building
char	*read_map_file(char *map_name);
char	**fill_map(char *map_str);
t_point	set_size(char **matrix);

// map_checking
int		check_borders(char **matrix);
int		read_map(char **matrix, char c);
int		count_elements(char **matrix);
int		check_valid_chars(char *map_str);
int		check_empty_line(char *map_str);

// map_validation
int		map_validation(char *map_name);
int		map_ext(const char *map_name);
int		is_rectangle(char **matrix);
int		flood_fill(char **matrix_dup, t_point size, t_point pos);
int		check_path(char **map, t_point size);

// render


// utils
char	**dup_map(char **matrix);
int		get_width(char **matrix);
int		get_height(char **matrix);
void	print_matrix(char **matrix);

#endif
