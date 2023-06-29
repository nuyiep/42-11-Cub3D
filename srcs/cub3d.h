/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/29 17:47:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/srcs/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
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
# define WIN_H		800
# define WIN_W		1280
# define MINI_S		19 // don't change
# define MINI_PX	15 // don't change
# define SCALE		1.725 // don't change

/* Colors */
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define TBROWN		0x80964B00
# define TGREY		0xE0E0E0E0
# define GREY		0x00606060
# define BGREY		0x00E0E0EF
# define TWHITE		0x80FFFFFF
# define TBLACK		0x80000000
# define BLACK		0x00000000
# define TRANS		0xBB555555
# define WHITE		0xffffffff

# define BABYBLUE	0x0084aed9
# define LIGHTGREEN 0x0090EE90
# define LIGHTPINK  0x00FFB6C1
# define LIGHTPURPLE  0x007068d9

# define PI			3.141592653589793238
# define ROT_SPD	0.1
# define MOV_SPD	0.2
# define PLY_PLANE	0.77

/* Door */
# define D_OPEN		1
# define D_CLOSE	0

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

/**
 * @brief Int vector struct
 * @param x X value in int
 * @param y Y value in int
 */
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/**
 * @brief Double vector struct
 * @param x X value in double
 * @param y Y value double
 */
typedef struct s_dvector
{
	double	x;
	double	y;
}	t_dvector;

/**
 * @brief Image struct 
 * 		  (for North, South, East, West)
 * @param ptr 		Image pointer
 * @param addr  	Address of image
 * @param bpp		Bits per pixel of image 
 * 					(value will be set by the function)
 * @param line_len	Size in bytes of a single image row 
 * 					(value will be set by the function)
 * @param endian    endian value (value will be set by the function)
 * 					A pointer to an integer variable
 * 					The value will be either 0 (little-endian) or 
 * 					1 (big-endian)
 * @param size      size (vector) (x & y) for the image
 * 
 * After calling the mlx_get_data_addr, the provided pointers bpp, 
 * line_len, endian will be updated with the corresponding values 
 * for the image.
 */
typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector	size;
}	t_img;

/**
 * @brief RGB struct 
 * 		  for floor and ceiling texture
 * @param r Red value
 * @param g Green value
 * @param b Blue value 
 */
typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

/**
 * @brief Map struct
 * @param map			Map
 * @param c_rgb			RGB struct for ceiling
 * @param f_rgb			RGB struct for floor
 * @param n_img			North image
 * @param e_img			East image
 * @param s_img			South image
 * @param w_img			West image
 * @param d_img			Door image
 * @param main			Main image
 * @param imgw			Window image
 * @param size			Size of the map (struct)- x, y
 * map size x = max strlen + 2 (\n & \0)
 * @param mm_scale		(??)
 * @param mini			Image struct for minimap
 * @param door_state	To be set manually (0 or 1)
 * 						Whether there is a door in the map
 */
typedef struct s_map
{
	char		**map;
	t_rgb		c_rgb;
	t_rgb		f_rgb;
	t_img		n_img;
	t_img		e_img;
	t_img		s_img;
	t_img		w_img;
	t_img		d_img;
	t_img		*main;
	t_img		imgw;
	t_vector	size;
	double		mm_scale;
	t_img		*mini;
	int			door_state;
}	t_map;

/**
 * @brief Player struct
 * [OK] @param char_dir	character for direction (N, S, W, E)
 * @param img		Image
 * [OK] @param map_pos	Map position (x, y)
 * @param pos		Position * MINI_PX (x, y)
 * @param dir		Direction | E.g. North is x = 0, y = -1
 * @param plane		Plane (x, y)
 * @param rotate	Rotate (x, y) 
 * 
 */
typedef struct s_ply
{
	char		char_dir;
	t_img		img;
	t_dvector	pos;
	t_dvector	dir;
	t_dvector	plane;
	double		rotate;
}	t_ply;

typedef struct s_rayinfo
{
	t_dvector	delta_dist;
	t_dvector	side_dist;
	t_dvector	offset;
	t_dvector	raydir;
	t_dvector	step;
	t_vector	map;
	double		perp_wall_dist;
	double		camera_x;
	double		wall_x;
	int			line_h;
	int			d_start;
	int			d_end;
	int			tex_x;
	int			side;
	int			hit;
}	t_rayinfo;

/* Master struct for variables */
/**
 * @brief Master struct for variables
 * @param 
 */
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_vector	img_size;
	t_map		map;
	t_ply		player;
	t_rayinfo	ray_info;
}	t_vars;

/* 1. Validation */
char	**valid_check_file_textures(int argc, char **argv, t_vars *vars);
void	map_checking(t_vars *vars, char **temp_map);
int		check_correct_order(char *str, int check);
void	check_only_one_player(char **temp_map);
void	check_invalid_character(char **temp_map, t_vars *vars);
void	check_middle_map_line(t_vars *vars);
void	check_rgb_format(char **split);
void	check_extra_character(char **split);
void	check_empty_lines(char **temp_map);
void	check_first_and_last_char(char **temp_map);
void	check_for_ones(char *str, int i);

/* Initialization */
void	init_vars(t_vars *vars);
void	update_player(t_vars *vars);
void	store_player_mpos(t_vars *vars);
void	store_player_dir(t_vars *vars);

/* Parsing */
int		store_temp_map(char *str, int k, char **temp_map);
void	store_map_size_x(t_vars *vars, char **temp_map);
void	store_player_dir_north_south(t_vars *vars);
void	store_player_dir_east_west(t_vars *vars);
char	**get_map_trim_newline(t_vars *vars, char **temp_map);
void	split_file_into_two_parts(char *file, t_vars *vars,
			int count, char **temp_map);
int		split_elements_north(t_vars *vars, char *str, int x);
int		split_elements_south(t_vars *vars, char *str, int x);
int		split_elements_east(t_vars *vars, char *str, int x);
int		split_elements_west(t_vars *vars, char *str, int x);
int		split_elements_door(t_vars *vars, char *str, int x);
int		split_elements_floor(t_vars *vars, char *str, int x);
int		split_elements_ceiling(t_vars *vars, char *str, int x);
void	pad_map_with_spaces(t_vars *vars, char **temp_map);

/* 3. Render */
int		render_main(t_vars *vars);
void	render_minimap(t_vars *vars);
void	render_rays(t_vars *vars);
void	set_length(t_vars *vars);
t_img	*set_image(t_vars *vars);
void	set_textures(t_vars *vars, t_img *curimg);

/* 4. Controls */
void	ctrl_run_hooks(t_vars *vars);
void	mouse_input(t_vars *vars);
t_bool	check_side_collision(t_vars *vars);
t_bool	check_front_collision(t_vars *vars, double dir);

/* Utils */
void	utils_print_error_exit(char *str);
int		ft_count_lines(int fd);
void	free_all(t_vars *vars);
void	print_map(char **map);
int		success_exit(void);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	convert_rgb_to_hex(t_vars *vars);

#endif
