/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/15 15:57:52 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/srcs/libft.h"
# include <mlx.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Player prefs */
# define WIN_H		1280
# define WIN_W		800

/* Vector struct */
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/* Image struct */
typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector	size;
}	t_img;

/* RGB struct - Ceiling and Floor */
typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

/* Map struct */
typedef struct s_map
{
	char		**map;
	t_rgb		c_rgb;
	t_rgb		f_rgb;
	t_img		n_img;
	t_img		e_img;
	t_img		s_img;
	t_img		w_img;
	t_img		*main;
	t_img		imgw;
	t_vector	size;
}	t_map;

/* Main struct */
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_vars;

/* 1. Validation */
char	**valid_check_file_textures(int argc, char **argv, t_vars *vars);
void	map_checking(t_vars *vars, char **temp_map);
int		check_correct_order(char *str, int check);
void	check_only_one_player(char **temp_map);
void	check_invalid_character(char **temp_map);
void	check_middle_zeros_surrounded_by_ones(t_vars *vars, char **temp_map);

/* Initialization */
void	init_vars(t_vars *vars);

/* Parsing */
int		store_map(char *str, int k, char **temp_map);
void	store_map_size_y(t_vars *vars, char **temp_map);
char	**get_map_trim_newline(t_vars *vars, char **temp_map);
void	split_file_into_two_parts(char *file, t_vars *vars,
			int count, char **temp_map);
int		split_elements_north(t_vars *vars, char *str, int x);
int		split_elements_south(t_vars *vars, char *str, int x);
int		split_elements_east(t_vars *vars, char *str, int x);
int		split_elements_west(t_vars *vars, char *str, int x);
void	pad_map_with_spaces(t_vars *vars, char **temp_map);

/* Utils */
void	utils_print_error_exit(char *str);
char	*ft_trim_space_tab_newline(char *str);
int		ft_count_lines(int fd);
void	free_all(t_vars *vars);
void	print_map(char **map);
void	check_rgb_format(char **split);

#endif
