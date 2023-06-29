#include "../cub3d.h"


void	set_length(t_vars *vars)
{
	vars->ray_info.line_h = (int)(WIN_H / vars->ray_info.perp_wall_dist);
	vars->ray_info.d_start = -vars->ray_info.line_h / 2 + WIN_H / 2;
	vars->ray_info.d_end = vars->ray_info.line_h / 2 + WIN_H / 2;
	if (vars->ray_info.side == 0)
		vars->ray_info.wall_x = vars->ray_info.offset.y
			+ vars->ray_info.perp_wall_dist * vars->ray_info.raydir.y;
	else
		vars->ray_info.wall_x = vars->ray_info.offset.x
			+ vars->ray_info.perp_wall_dist * vars->ray_info.raydir.x;
	vars->ray_info.wall_x -= floor((vars->ray_info.wall_x));
}

t_img	*set_image(t_vars *vars)
{
	t_img	*curimg;

	if (vars->ray_info.side == 0)
	{
		if (vars->ray_info.step.x == 1)
			curimg = &vars->map.e_img;
		else
			curimg = &vars->map.w_img;
	}
	else
	{
		if (vars->ray_info.step.y == 1)
			curimg = &vars->map.s_img;
		else
			curimg = &vars->map.n_img;
	}
	return (curimg);
}

void	set_textures(t_vars *vars, t_img *curimg)
{
	vars->ray_info.tex_x = (int)(vars->ray_info.wall_x * (double)(curimg->size.x));
	if (vars->ray_info.side == 0)
	{
		if (vars->ray_info.raydir.x > 0)
			vars->ray_info.tex_x = curimg->size.x
				- (curimg->size.x - vars->ray_info.tex_x - 1);
		else
			vars->ray_info.tex_x = curimg->size.x
				- vars->ray_info.tex_x - 1;
	}
	if (vars->ray_info.side == 1)
	{
		if (vars->ray_info.raydir.y < 0)
			vars->ray_info.tex_x = curimg->size.x
				- (curimg->size.x - vars->ray_info.tex_x - 1);
		else
			vars->ray_info.tex_x = curimg->size.x
				- vars->ray_info.tex_x - 1;
	}
}