/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 18:59:57 by zwong            ###   ########.fr       */
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
# define MINI_S		19
# define MINI_PX	15
# define SCALE		1.725

/* Colors */
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define TBROWN		0x80964B00
# define TGREY		0xE0E0E0E0
# define TWHITE		0x80FFFFFF
# define TBLACK		0x80000000
# define TRANS		0xFF000000

# define PI			3.141592653589793238
# define ROT_SPD	0.1
# define MOV_SPD	0.025

/* X and Y vector */
typedef struct s_vector
{
	int x;
	int y;
}	t_vector;

/* Doubles X and Y vector */
typedef struct s_dvector
{
	double	x;
	double	y;
}	t_dvector;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector	size;
}	t_img;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				hex;
}	t_rgb;

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
	// int		door_state;
}	t_map;

typedef struct s_ply
{
	t_img		img;
	t_dvector	pos;
	t_vector	mpos;
	t_dvector	dir;
	double		rotate;
}	t_ply;

/* Master struct for variables */
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_vector	img_size;
	t_map		map;
	t_ply		player;
	// t_render	render;
}	t_vars;

/* Initialization */
void	init_vars(t_vars *vars);

/* 1. Validation */
void	valid_check_file(int argc, char **argv);

/* 3. Render */
int		render_main(t_vars *vars);
void	draw_player(t_vars *vars);
void	draw_dir(t_vars *vars);
void	render_minimap(t_vars *vars);

/* 4. Controls */
void	ctrl_run_hooks(t_vars *vars);

/* Utils */
void	print_error_exit(char *str, char *arg);
int		success_exit();
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
