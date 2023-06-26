/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:14 by zwong             #+#    #+#             */
/*   Updated: 2023/06/26 19:19:52 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clearimgwindow(t_vars *vars)
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
				my_mlx_pixel_put(&vars->map.imgw, i, k, BLACK);
			else
				my_mlx_pixel_put(&vars->map.imgw, i, k, BLACK);
			k++;
		}
		i++;
	}
}

int	render_main(t_vars *vars)
{
	clearimgwindow(vars);
	mlx_clear_window(vars->mlx, vars->win);
	render_rays(vars);
	render_minimap(vars);
	return (0);
}
