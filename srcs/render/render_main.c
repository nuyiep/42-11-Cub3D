/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:14 by zwong             #+#    #+#             */
/*   Updated: 2023/06/29 16:53:36 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Update ceiling and floor color */
void	reset_background(t_vars *vars)
{
	int	i;
	int	k;

	i = 0;
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			if (k < WIN_H / 2)
				my_mlx_pixel_put(&vars->map.imgw, i, k, vars->map.c_rgb.hex);
			else 
				my_mlx_pixel_put(&vars->map.imgw, i, k, vars->map.f_rgb.hex);
			k++;
		}
		i++;
	}
}

int	render_main(t_vars *vars)
{
	reset_background(vars);
	mlx_clear_window(vars->mlx, vars->win);
	// mouse_input(vars);
	render_rays(vars);
	render_minimap(vars);
	return (0);
}
