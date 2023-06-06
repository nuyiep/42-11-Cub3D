/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:57 by plau              #+#    #+#             */
/*   Updated: 2023/06/06 18:05:20 by plau             ###   ########.fr       */
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

/* Map struct */
typedef struct s_map
{
	t_vector	size;
	
}	t_map;

/* Main struct */
typedef struct s_game
{
	void	*mlx;
	t_map	map;
}	t_game;

/* 1. Validation */
void	valid_check_file(int argc, char **argv, t_game *game);

/* Utils */
void	utils_print_error_exit(char *str);

#endif
