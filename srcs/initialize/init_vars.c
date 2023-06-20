/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:18 by plau              #+#    #+#             */
/*   Updated: 2023/06/20 20:38:40 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Initializes MLX and the Window configurations */
static void	init_mlx_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "cub3d");
}

static void	init_map(t_vars *vars)
{
	vars->map.n_img.ptr = NULL;
	vars->map.e_img.ptr = NULL;
	vars->map.s_img.ptr = NULL;
	vars->map.w_img.ptr = NULL;
	vars->map.d_img.ptr = NULL;
	vars->map.map = NULL;
	vars->map.c_rgb.hex = -1;
	vars->map.f_rgb.hex = -1;
	vars->map.main = ft_calloc(1, sizeof(t_img));
	vars->map.mini = ft_calloc(1, sizeof(t_img));
	vars->map.imgw.ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->map.size.x = 0;
	vars->map.size.y = 0;
	vars->map.imgw.addr = mlx_get_data_addr(vars->map.imgw.ptr,
			&vars->map.imgw.bpp, &vars->map.imgw.line_len,
			&vars->map.imgw.endian);
	vars->map.door_state = D_CLOSE;
}

void	update_player(t_vars *vars)
{
	get_player_mpos(vars);
}

// HARDCODED player position and direction to NORTH
/* Initialize player struct */
/* Plater direction in char is stored via check_only_one_player function */
void	init_player(t_vars *vars)
{
	// CHANGE BELOW
	vars->player.mpos.x = 8; // change this to actual map position
	vars->player.mpos.y = 11; // change this to actual map position

	vars->player.pos.x = 8 * MINI_PX; // mpos * MINI_PX
	vars->player.pos.y = 11 * MINI_PX; // mpos * MINI_PX
	
	// DO NOT CHANGE BELOW
	vars->player.dir.x = 0; // N 0
	vars->player.dir.y = -1; // N -1
	vars->player.rotate = -PI/2; // don't change this is for North
	
	vars->player.plane.x = 1; // N 1
	vars->player.plane.y = 0; // N 0
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
