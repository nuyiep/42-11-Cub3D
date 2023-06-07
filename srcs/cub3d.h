/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/07 20:23:49 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/srcs/libft.h"
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

/* Vector struct */
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/* Image struct */
typedef struct s_img
{
	void	*ptr;
	char	*str;
}	t_img;

/* Map struct */
typedef struct s_map
{
	t_vector	size;
	t_img		n_img;
	t_img		e_img;
	t_img		w_img;
	t_img		s_img;
	
}	t_map;

/* Main struct */
typedef struct s_game
{
	void	*mlx;
	t_map	map;
}	t_game;

/* 1. Validation */
void	valid_check_file(int argc, char **argv, t_game *game);
void	split_elements(t_game *game, char *str);

/* Utils */
void	utils_print_error_exit(char *str);
char	*ft_trim_space_tab(char *str);
int		ft_count_lines(int fd);

#endif
