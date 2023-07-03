/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:32:22 by zwong             #+#    #+#             */
/*   Updated: 2023/07/03 13:17:05 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_new_ray(t_vars *vars, int ray_i)
{
	vars->ray.camera_x = 2 * ray_i / (double)WIN_W - 1;
	vars->ray.raydir.x
		= vars->player.dir.x + vars->player.plane.x * vars->ray.camera_x;
	vars->ray.raydir.y
		= vars->player.dir.y + vars->player.plane.y * vars->ray.camera_x;
	vars->ray.offset.x = vars->player.pos.x + 0.5;
	vars->ray.offset.y = vars->player.pos.y + 0.5;
	vars->ray.map.x = vars->ray.offset.x;
	vars->ray.map.y = vars->ray.offset.y;
	if (vars->ray.raydir.x == 0)
		vars->ray.del_dist.x = 1e30;
	else
		vars->ray.del_dist.x = fabs(1 / vars->ray.raydir.x);
	if (vars->ray.raydir.y == 0)
		vars->ray.del_dist.y = 1e30;
	else
		vars->ray.del_dist.y = fabs(1 / vars->ray.raydir.y);
	vars->ray.hit = 0;
}

static void	check_steps(t_vars *vars)
{
	if (vars->ray.raydir.x < 0)
	{
		vars->ray.step.x = -1;
		vars->ray.side_dist.x = (vars->ray.offset.x - vars->ray.map.x)
			* vars->ray.del_dist.x;
	}
	else
	{
		vars->ray.step.x = 1;
		vars->ray.side_dist.x = (vars->ray.map.x + 1.0 - vars->ray.offset.x)
			* vars->ray.del_dist.x;
	}
	if (vars->ray.raydir.y < 0)
	{
		vars->ray.step.y = -1;
		vars->ray.side_dist.y = (vars->ray.offset.y - vars->ray.map.y)
			* vars->ray.del_dist.y;
	}
	else
	{
		vars->ray.step.y = 1;
		vars->ray.side_dist.y = (vars->ray.map.y + 1.0 - vars->ray.offset.y)
			* vars->ray.del_dist.y;
	}
}

static void	check_hit(t_vars *vars)
{
	while (vars->ray.hit == 0)
	{
		if (vars->ray.side_dist.x < vars->ray.side_dist.y)
		{
			vars->ray.side_dist.x += vars->ray.del_dist.x;
			vars->ray.map.x += vars->ray.step.x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.side_dist.y += vars->ray.del_dist.y;
			vars->ray.map.y += vars->ray.step.y;
			vars->ray.side = 1;
		}
		if (vars->ray.map.y < 0 || vars->ray.map.y >= vars->map.size.y
			|| vars->ray.map.x < 0 || vars->ray.map.x >= vars->map.size.x)
			break ;
		else if (vars->map.map[vars->ray.map.y][vars->ray.map.x] == '1')
			vars->ray.hit = 1;
	}
	if (vars->ray.side == 0)
		vars->ray.perp_wdist = (vars->ray.side_dist.x - vars->ray.del_dist.x);
	else
		vars->ray.perp_wdist = (vars->ray.side_dist.y - vars->ray.del_dist.y);
}

static void	draw_line(t_vars *vars, t_img *img, int i)
{
	char	*dest;
	double	y;
	int		color;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(vars->ray.d_end - vars->ray.d_start));
	while (vars->ray.d_start < vars->ray.d_end)
	{
		if (vars->ray.d_start >= 0 && vars->ray.d_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->line_len
					+ vars->ray.tex_x * (img->bpp / 8));
			color = *(unsigned int *)dest;
			my_mlx_pixel_put(&vars->map.imgw, i, vars->ray.d_start, color);
		}
		vars->ray.d_start++;
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
