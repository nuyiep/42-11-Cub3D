#include "../cub3d.h"

void	create_new_ray(t_vars *vars, int ray_i)
{
	vars->ray_info.camera_x = 2 * ray_i / (double)WIN_W - 1;
	vars->ray_info.raydir.x = vars->player.dir.x + vars->player.plane.x * vars->ray_info.camera_x;
	vars->ray_info.raydir.y = vars->player.dir.y + vars->player.plane.y * vars->ray_info.camera_x;
	// printf("PLayer direction: (%f, %f)\n", vars->player.dir.x, vars->player.dir.y);

	// Setting player position in map. Need offset?
	// printf("PLayer map pos: (%d, %d)\n", vars->player.mpos.x, vars->player.mpos.y);
	vars->ray_info.offset.x = vars->player.pos.x + 0.5;
	vars->ray_info.offset.y = vars->player.pos.y + 0.5;
	vars->ray_info.map.x = vars->ray_info.offset.x;
	vars->ray_info.map.y = vars->ray_info.offset.y;

	// Setting the delta distance
	if (vars->ray_info.raydir.x == 0)
		vars->ray_info.delta_dist.x = 1e30;
	else
		vars->ray_info.delta_dist.x = fabs(1 / vars->ray_info.raydir.x);
	if (vars->ray_info.raydir.y == 0)
		vars->ray_info.delta_dist.y = 1e30;
	else
		vars->ray_info.delta_dist.y = fabs(1 / vars->ray_info.raydir.y);
	
	// printf("Delta distance of ray: (%f, %f)\n", vars->ray_info.delta_dist.x, vars->ray_info.delta_dist.y);
	// Not hitting any wall, set to 1 when hit
	vars->ray_info.hit = 0;
}

void	check_steps(t_vars *vars)
{
	if (vars->ray_info.raydir.x < 0)
	{
		vars->ray_info.step.x = -1;
		vars->ray_info.side_dist.x = (vars->ray_info.offset.x - vars->ray_info.map.x)
			* vars->ray_info.delta_dist.x;
	}
	else
	{
		vars->ray_info.step.x = 1;
		vars->ray_info.side_dist.x = (vars->ray_info.map.x + 1.0 - vars->ray_info.offset.x)
			* vars->ray_info.delta_dist.x;
	}
	if (vars->ray_info.raydir.y < 0)
	{
		vars->ray_info.step.y = -1;
		vars->ray_info.side_dist.y = (vars->ray_info.offset.y - vars->ray_info.map.y)
			* vars->ray_info.delta_dist.y;
	}
	else
	{
		vars->ray_info.step.y = 1;
		vars->ray_info.side_dist.y = (vars->ray_info.map.y + 1.0 - vars->ray_info.offset.y)
			* vars->ray_info.delta_dist.y;
	}
}

static void	check_hit(t_vars *vars)
{
	while (vars->ray_info.hit == 0)
	{
		if (vars->ray_info.side_dist.x < vars->ray_info.side_dist.y)
		{
			vars->ray_info.side_dist.x += vars->ray_info.delta_dist.x;
			vars->ray_info.map.x += vars->ray_info.step.x;
			vars->ray_info.side = 0;
		}
		else
		{
			vars->ray_info.side_dist.y += vars->ray_info.delta_dist.y;
			vars->ray_info.map.y += vars->ray_info.step.y;
			vars->ray_info.side = 1;
		}
		// printf("Checking wall coordinate (%d, %d)\n", (int)vars->ray_info.map.x, (int)vars->ray_info.map.y);
		if (vars->ray_info.map.y < 0 || vars->ray_info.map.y >= vars->map.size.y || vars->ray_info.map.x < 0 || vars->ray_info.map.x >= vars->map.size.x)
			break ;
		else if (vars->map.map[(int)vars->ray_info.map.y][(int)vars->ray_info.map.x] == '1')
			vars->ray_info.hit = 1;
	}

	if (vars->ray_info.side == 0)
		vars->ray_info.perp_wall_dist = (vars->ray_info.side_dist.x
				- vars->ray_info.delta_dist.x);
	else
		vars->ray_info.perp_wall_dist = (vars->ray_info.side_dist.y
				- vars->ray_info.delta_dist.y);
	// t_dvector dest;

	// dest.x = vars->ray_info.perp_wall_dist * vars->ray_info.raydir.x;
	// dest.y = vars->ray_info.perp_wall_dist * vars->ray_info.raydir.y;
	// draw_diagonal(vars, vars->ray_info.raydir, dest);
}

void	set_length(t_vars *vars)
{
	vars->ray_info.line_h = (int)(WIN_H / vars->ray_info.perp_wall_dist);
	vars->ray_info.d_start = -vars->ray_info.line_h / 2 + WIN_H / 2;
	if (vars->ray_info.d_start < 0)
		vars->ray_info.d_start = 0;
	vars->ray_info.d_end = vars->ray_info.line_h / 2 + WIN_H / 2;
	if (vars->ray_info.d_end >= WIN_H)
		vars->ray_info.d_end = WIN_H - 1;
	if (vars->ray_info.side == 0)
		vars->ray_info.wall_x = vars->ray_info.offset.y
			+ vars->ray_info.perp_wall_dist * vars->ray_info.raydir.y;
	else
		vars->ray_info.wall_x = vars->ray_info.offset.x
			+ vars->ray_info.perp_wall_dist * vars->ray_info.raydir.x;
	vars->ray_info.wall_x -= floor((vars->ray_info.wall_x));
}

// void	check_sides(t_vars *vars, t_img *curimg)
// {
// 	vars->ray_info.tex_x = (int)(vars->ray_info.wall_x * (double)(curimg->size.x));
// 	if (vars->ray_info.side == 0)
// 	{
// 		if (vars->ray_info.raydir.x > 0)
// 			vars->ray_info.tex_x = curimg->size.x
// 				- (curimg->size.x - vars->ray_info.tex_x - 1);
// 		else
// 			vars->ray_info.tex_x = curimg->size.x
// 				- vars->ray_info.tex_x - 1;
// 	}
// 	if (vars->ray_info.side == 1)
// 	{
// 		if (vars->ray_info.raydir.y < 0)
// 			vars->ray_info.tex_x = curimg->size.x
// 				- (curimg->size.x - vars->ray_info.tex_x - 1);
// 		else
// 			vars->ray_info.tex_x = curimg->size.x
// 				- vars->ray_info.tex_x - 1;
// 	}
// }

// void	c3d_draw_verline(t_img *img, int i, t_gm *gm)
// {
// 	char	*dest;
// 	double	y;
// 	int		color;
// 	double	factor;

// 	y = 0;
// 	factor = ((double)(img->size.y - 1)
// 			/ (double)(gm->render.d_end - gm->render.d_start));
// 	while (gm->render.d_start < gm->render.d_end)
// 	{
// 		if (gm->render.d_start >= 0 && gm->render.d_start < WIN_H)
// 		{
// 			dest = img->addr + ((int)y * img->sl
// 					+ gm->render.tex_x * (img->bpp / 8));
// 			color = *(unsigned int *)dest;
// 			c3d_my_mlx_pixel_put(&gm->map.imgw, i, gm->render.d_start, color);
// 		}
// 		gm->render.d_start++;
// 		y = y + factor;
// 	}
// }

void	draw_line(t_vars *vars, int x, int start, int end, int colour)
{
	while (start < end)
		my_mlx_pixel_put(&vars->map.imgw, x, start++, colour);
}

void	render_rays(t_vars *vars)
{
	int	ray_i;

	ray_i = -1;
	while (++ray_i < WIN_W)
	{
		create_new_ray(vars, ray_i);
		check_steps(vars);
		check_hit(vars);
		set_length(vars);
		// check sides
		draw_line(vars, ray_i, vars->ray_info.d_start, vars->ray_info.d_end, RED);
		// my_mlx_pixel_put(&vars->map.imgw, ray_i, 500, RED);
		// draw_line(vars, ray_i, 250, 750, BLUE);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.imgw.ptr, 0, 0);
}
