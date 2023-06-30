/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:19:44 by zwong             #+#    #+#             */
/*   Updated: 2023/06/30 11:41:11 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_player(t_vars *vars)
{
	t_dvector	pos;

	pos.x = MINI_S * MINI_PX / 2;
	pos.y = MINI_S * MINI_PX / 2;
	my_mlx_pixel_put(vars->map.mini, pos.x - 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x + 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x - 1, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x + 1, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x - 1, pos.y + 1, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x, pos.y + 1, GREEN);
	my_mlx_pixel_put(vars->map.mini, pos.x + 1, pos.y + 1, GREEN);
}

static void	draw_dir(t_vars *vars)
{
	t_dvector	pos;
	t_dvector	dir;
	int			i;

	pos.x = MINI_S * MINI_PX / 2;
	pos.y = MINI_S * MINI_PX / 2;
	dir.x = vars->player.dir.x;
	dir.y = vars->player.dir.y;
	i = -1;
	while (i++ <= 15)
	{
		my_mlx_pixel_put(vars->map.mini, (int)(dir.x * i + pos.x),
			(int)(dir.y * i + pos.y), RED);
	}
}

static void	loop_minimap(t_vars *vars, t_vector min, t_vector max)
{
	t_vector	cur;
	t_vector	scale;
	t_vector	map;

	cur.y = min.y;
	while (++cur.y < max.y)
	{
		cur.x = min.x;
		while (++cur.x < max.x)
		{
			map.x = cur.x / MINI_PX;
			map.y = cur.y / MINI_PX;
			scale.y = (cur.y - min.y) * SCALE;
			scale.x = (cur.x - min.x) * SCALE;
			if (map.x < 0 || map.y < 0 || map.x > (vars->map.size.x - 1)
				|| map.y > (vars->map.size.y - 1))
				colour_block(vars->map.mini, scale, MINI_PX * SCALE, TRANS);
			else if (vars->map.map[map.y][map.x] == '1')
				colour_block(vars->map.mini, scale, MINI_PX * SCALE, LIGHTPURP);
			else
				colour_block(vars->map.mini, scale, MINI_PX * SCALE, TWHITE);
		}
	}
}

static void	draw_minimap(t_vars *vars)
{
	t_vector	max;
	t_vector	min;

	if (vars->map.mini->ptr != NULL)
		mlx_destroy_image(vars->mlx, vars->map.mini->ptr);
	vars->map.mini->ptr
		= mlx_new_image(vars->mlx, MINI_S * MINI_PX, MINI_S * MINI_PX);
	vars->map.mini->addr
		= mlx_get_data_addr(vars->map.mini->ptr,
			&vars->map.mini->bpp, &vars->map.mini->line_len,
			&vars->map.mini->endian);
	colour_block(vars->map.mini, (t_vector){0, 0}, MINI_S * MINI_PX, TGREY);
	min.y = vars->player.pos.y * MINI_PX - (5 * MINI_PX) - 1;
	max.y = vars->player.pos.y * MINI_PX + (5 * MINI_PX) + 1;
	min.x = vars->player.pos.x * MINI_PX - (5 * MINI_PX) - 1;
	max.x = vars->player.pos.x * MINI_PX + (5 * MINI_PX) + 1;
	loop_minimap(vars, min, max);
}

void	render_minimap(t_vars *vars)
{
	draw_minimap(vars);
	draw_player(vars);
	draw_dir(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.mini->ptr, 0, 0);
}
