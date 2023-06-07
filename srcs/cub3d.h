/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/06 15:16:12 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/srcs/libft.h"
#include <stdio.h>
#include <mlx.h>

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

/* X and Y vector */
typedef struct s_vector
{
	int x;
	int y;
}	t_vector;

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
	// t_img	*mini;
	// int		door_state;
}	t_map;

/* Master struct for variables */
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
	t_vector	img_size;
	t_map		map;
	// t_ply		player;
	// t_render	render;
}	t_vars;

/* Initialization */
void	init_vars(t_vars *vars);

/* 1. Validation */
void	valid_check_file(int argc, char **argv);

/* Utils */
void	print_error_exit(char *str, char *arg);

#endif
