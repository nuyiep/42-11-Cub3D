/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:18 by plau              #+#    #+#             */
/*   Updated: 2023/06/30 11:48:10 by zwong            ###   ########.fr       */
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
	vars->mouse_key = 0;
}

void	update_player(t_vars *vars)
{
	store_player_mpos(vars);
	store_player_dir_north_south(vars);
	store_player_dir_east_west(vars);
}

/* Initialize player struct */
void	init_player(t_vars *vars)
{
	vars->player.pos.x = 0;
	vars->player.pos.y = 0;
	vars->player.dir.x = 0;
	vars->player.dir.y = 0;
	vars->player.rotate = 0;
	vars->player.plane.x = 0;
	vars->player.plane.y = 0;
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
