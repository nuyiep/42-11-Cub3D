/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:43:27 by zwong             #+#    #+#             */
/*   Updated: 2023/06/30 11:48:19 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_hook(int x, int y, t_vars *vars)
{
	double	rotate_spd;
	double	plane_rotate;

	if (vars->mouse_key == 1)
	{
		rotate_spd = PI / (double)(WIN_W / 2);
		mlx_mouse_get_pos(vars->win, &x, &y);
		vars->player.rotate = rotate_spd * x;
		plane_rotate = vars->player.rotate + (PI / 2);
		vars->player.dir.x = cos(vars->player.rotate);
		vars->player.dir.y = sin(vars->player.rotate);
		vars->player.plane.x = cos(plane_rotate);
		vars->player.plane.y = sin(plane_rotate);
	}
	return (0);
}

void	toggle_mouse(t_vars *vars)
{
	if (vars->mouse_key == 0)
	{
		// mlx_mouse_hide();
		mlx_mouse_move(vars->win, WIN_W / 2, WIN_H / 2);
		vars->mouse_key = 1;
	}
	else
	{
		// mlx_mouse_show();
		vars->mouse_key = 0;
	}
}
