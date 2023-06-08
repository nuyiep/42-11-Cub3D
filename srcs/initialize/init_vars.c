/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:18 by plau              #+#    #+#             */
/*   Updated: 2023/06/08 15:30:33 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Initializes MLX and the Window configurations */
static void	init_mlx_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	//vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "cub3d");
}

static void	init_map(t_vars *vars)
{
	vars->map.n_img.ptr = NULL;
	vars->map.e_img.ptr = NULL;
	vars->map.s_img.ptr = NULL;
	vars->map.w_img.ptr = NULL;
	vars->mlx = NULL;
	//vars->map.d_img.ptr = NULL;
	//vars->map.map = NULL;
	vars->map.c_rgb.hex = -1;
	vars->map.f_rgb.hex = -1;
	vars->map.main = ft_calloc(1, sizeof(t_img));
	// vars->map.door_state = D_OPEN;
	// vars->map.mini = ft_calloc(1, sizeof(t_img));
	// vars->map.imgw.ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	// vars->map.imgw.addr = mlx_get_data_addr(vars->map.imgw.ref, &vars->map.imgw.bpp,
	// 		&vars->map.imgw.sl, &vars->map.imgw.end);
}

static void	init_player(t_vars *vars)
{
	(void)vars;
	return ;
}

/**
 * @brief Master initialize function for mlx, map and player. 
 * 
 * @param vars Master struct
 */
void	init_vars(t_vars *vars)
{
	init_mlx_window(vars);
	init_map(vars);
	init_player(vars);
}