#include "../cub3d.h"

void	create_new_ray(t_vars *vars, int ray_i)
{
	vars->ray_info.camera_x = 2 * ray_i / (double)WIN_W - 1;
	vars->ray_info.raydir.x = vars->player.dir.x + vars->player.plane.x * vars->ray_info.camera_x;
	vars->ray_info.raydir.y = vars->player.dir.y + vars->player.plane.y * vars->ray_info.camera_x;

	vars->ray_info.offset.x = vars->player.pos.x + 0.5;
	vars->ray_info.offset.y = vars->player.pos.y + 0.5;
	vars->ray_info.map.x = vars->ray_info.offset.x;
	vars->ray_info.map.y = vars->ray_info.offset.y;

	if (vars->ray_info.raydir.x == 0)
		vars->ray_info.delta_dist.x = 1e30;
	else
		vars->ray_info.delta_dist.x = fabs(1 / vars->ray_info.raydir.x);
	if (vars->ray_info.raydir.y == 0)
		vars->ray_info.delta_dist.y = 1e30;
	else
		vars->ray_info.delta_dist.y = fabs(1 / vars->ray_info.raydir.y);

	vars->ray_info.hit = 0;
}

static void	check_steps(t_vars *vars)
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
}

static void	draw_line(t_vars *vars, t_img *img, int i)
{
	char	*dest;
	double	y;
	int		color;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(vars->ray_info.d_end - vars->ray_info.d_start));
	while (vars->ray_info.d_start < vars->ray_info.d_end)
	{
		if (vars->ray_info.d_start >= 0 && vars->ray_info.d_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->line_len
					+ vars->ray_info.tex_x * (img->bpp / 8));
			color = *(unsigned int *)dest;
			my_mlx_pixel_put(&vars->map.imgw, i, vars->ray_info.d_start, color);
		}
		vars->ray_info.d_start++;
		y = y + factor;
	}
}

void	render_rays(t_vars *vars)
{
	int		ray_i;
	t_img	*curimg;

	ray_i = -1;
	while (++ray_i < WIN_W)
	{
		create_new_ray(vars, ray_i);
		check_steps(vars);
		check_hit(vars);
		set_length(vars);
		curimg = set_image(vars);
		set_textures(vars, curimg);
		draw_line(vars, curimg, ray_i);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.imgw.ptr, 0, 0);
}
