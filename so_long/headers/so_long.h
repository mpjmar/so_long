/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:48:29 by maria-j2          #+#    #+#             */
/*   Updated: 2025/09/11 19:51:19 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/MLX42.h"
# include <fcntl.h>
# include <errno.h>

# define TILE_SIZE 128

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_player
{
	t_point		pos;
	t_point		next_pos;
	int			moves;
	mlx_image_t	*img;
}				t_player;

typedef struct s_vars
{
	mlx_t		*mlx;
	char		**map;
	int			items;
	int			moves;
	t_point		exit;
	t_player	player;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*exit_img;
}				t_vars;

// events
void	key_handler(mlx_key_data_t keydata, void *param);
void 	update_player_pos(t_vars *vars, char mov);
void	move_player(t_vars *vars, char mov);
void	close_handler(void *param);

// free and errors
void	free_matrix(char **matrix);
void	ft_error(int error);

// game
t_point	find_player(char **matrix);
int		items_count(t_vars *vars);
mlx_t	*init_game(char **map);
void	init_vars(t_vars *vars, mlx_t *mlx, char **map);
void	loop_handler(void *param);

// main
int		main(int argc, char **argv);

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
void	init_map(t_vars *vars);
void	render_map(t_vars *vars);

// utils
char	**dup_map(char **matrix);
int		get_width(char **matrix);
int		get_height(char **matrix);
void	print_matrix(char **matrix);

#endif
