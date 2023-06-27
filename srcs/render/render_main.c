/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:14 by zwong             #+#    #+#             */
/*   Updated: 2023/06/27 20:52:20 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	convert_rgb_to_hex(t_vars *vars)
{
	vars->map.c_rgb.hex = 0 << 24 | vars->map.c_rgb.r << 16
							| vars->map.c_rgb.g << 8 | vars->map.c_rgb.b;
	vars->map.f_rgb.hex = 0 << 24 | vars->map.f_rgb.r << 16
							| vars->map.f_rgb.g << 8 | vars->map.f_rgb.b;
}

/* Update ceiling and floor color */
void	clear_image_window(t_vars *vars)
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
	clear_image_window(vars);
	mlx_clear_window(vars->mlx, vars->win);
	render_rays(vars);
	render_minimap(vars);
	return (0);
}
