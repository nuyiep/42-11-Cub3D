/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:14 by zwong             #+#    #+#             */
/*   Updated: 2023/06/28 17:45:42 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* In MLX, colours are presented in int format that contains the TRGB values */
/* Shift bits using the TRGB format */
/* T - transparency */
/* 0xTTRRGGBB format- 0x means that they are in hexa format */
/* T - 0 is opaque and 255 is fully transparent */
/* As the default background is black, fully transparent is black */
/* ft_printf("hex value: %08x\n", vars->map.f_rgb.hex) */
/* Bitshift formula is provided */
/* https://harm-smits.github.io/42docs/libs/minilibx/colors.html */
void	convert_rgb_to_hex(t_vars *vars)
{
	int	t;
	
	t = 0;
	vars->map.c_rgb.hex = t << 24 | vars->map.c_rgb.r << 16
							| vars->map.c_rgb.g << 8 | vars->map.c_rgb.b;
	vars->map.f_rgb.hex = t << 24 | vars->map.f_rgb.r << 16
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
