/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:29:18 by zwong             #+#    #+#             */
/*   Updated: 2023/06/30 11:41:49 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_length(t_vars *vars)
{
	vars->ray.line_h = (int)(WIN_H / vars->ray.perp_wdist);
	vars->ray.d_start = -vars->ray.line_h / 2 + WIN_H / 2;
	vars->ray.d_end = vars->ray.line_h / 2 + WIN_H / 2;
	if (vars->ray.side == 0)
		vars->ray.wall_x = vars->ray.offset.y
			+ vars->ray.perp_wdist * vars->ray.raydir.y;
	else
		vars->ray.wall_x = vars->ray.offset.x
			+ vars->ray.perp_wdist * vars->ray.raydir.x;
	vars->ray.wall_x -= floor((vars->ray.wall_x));
}

t_img	*set_image(t_vars *vars)
{
	t_img	*curimg;

	if (vars->ray.side == 0)
	{
		if (vars->ray.step.x == 1)
			curimg = &vars->map.e_img;
		else
			curimg = &vars->map.w_img;
	}
	else
	{
		if (vars->ray.step.y == 1)
			curimg = &vars->map.s_img;
		else
			curimg = &vars->map.n_img;
	}
	return (curimg);
}

void	set_textures(t_vars *vars, t_img *curimg)
{
	vars->ray.tex_x
		= (int)(vars->ray.wall_x * (double)(curimg->size.x));
	if (vars->ray.side == 0)
	{
		if (vars->ray.raydir.x > 0)
			vars->ray.tex_x = curimg->size.x
				- (curimg->size.x - vars->ray.tex_x - 1);
		else
			vars->ray.tex_x = curimg->size.x
				- vars->ray.tex_x - 1;
	}
	if (vars->ray.side == 1)
	{
		if (vars->ray.raydir.y < 0)
			vars->ray.tex_x = curimg->size.x
				- (curimg->size.x - vars->ray.tex_x - 1);
		else
			vars->ray.tex_x = curimg->size.x
				- vars->ray.tex_x - 1;
	}
}
