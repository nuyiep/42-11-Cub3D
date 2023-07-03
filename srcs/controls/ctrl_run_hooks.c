/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_run_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:43:32 by zwong             #+#    #+#             */
/*   Updated: 2023/07/03 13:24:02 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_player_vertical(int keycode, t_vars *vars)
{
	if (keycode == KEY_W && check_front_collision(vars, 1) == FALSE)
	{
		vars->player.pos.y += (double)(vars->player.dir.y * MOV_SPD);
		vars->player.pos.x += (double)(vars->player.dir.x * MOV_SPD);
	}
	else if (keycode == KEY_S && check_front_collision(vars, -1) == FALSE)
	{
		vars->player.pos.y -= (double)(vars->player.dir.y * MOV_SPD);
		vars->player.pos.x -= (double)(vars->player.dir.x * MOV_SPD);
	}
}

// Weird bug moving abit forward, not 100% horizontal
static void	move_player_horizontal(int keycode, t_vars *vars)
{
	if (keycode == KEY_A && check_side_collision(vars) == FALSE)
	{
		vars->player.pos.x = vars->player.pos.x
			+ (vars->player.dir.x * cos(-PI / 2)
				- vars->player.dir.y * sin(-PI / 2)) * MOV_SPD;
		vars->player.pos.y = vars->player.pos.y
			+ (vars->player.dir.y * cos(-PI / 2)
				+ vars->player.dir.x * sin(-PI / 2)) * MOV_SPD;
	}
	else if (keycode == KEY_D && check_side_collision(vars) == FALSE)
	{
		vars->player.pos.x = vars->player.pos.x
			+ (vars->player.dir.x * cos(PI / 2)
				- vars->player.dir.y * sin(PI / 2) * (MOV_SPD));
		vars->player.pos.y = vars->player.pos.y
			+ (vars->player.dir.y * cos(PI / 2)
				+ vars->player.dir.x * sin(PI / 2) * (MOV_SPD));
	}
}

static void	rotate_player(int keycode, t_vars *vars)
{
	double	plane_rotate;

	if (keycode == KEY_LEFT)
	{
		vars->player.rotate -= ROT_SPD;
		plane_rotate = vars->player.rotate + (PI / 2);
		if (vars->player.rotate < 0)
			vars->player.rotate += (2 * PI);
		vars->player.dir.x = cos(vars->player.rotate);
		vars->player.dir.y = sin(vars->player.rotate);
		vars->player.plane.x = cos(plane_rotate);
		vars->player.plane.y = sin(plane_rotate);
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->player.rotate += ROT_SPD;
		plane_rotate = vars->player.rotate + (PI / 2);
		if (vars->player.rotate > 2 * PI)
			vars->player.rotate -= (2 * PI);
		vars->player.dir.x = cos(vars->player.rotate);
		vars->player.dir.y = sin(vars->player.rotate);
		vars->player.plane.x = cos(plane_rotate);
		vars->player.plane.y = sin(plane_rotate);
	}
}

/**
 * @brief Executes functions according to key pressed. 
 * 			WASD and LEFT & RIGHT ARROW KEY 
 * 
 * @param keycode Keyboard keys represented as integer
 * @param vars Master game vars
 * @return int 
 */
static int	key_input(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		success_exit(vars);
	if (keycode == KEY_M)
		toggle_mouse(vars);
	move_player_vertical(keycode, vars);
	move_player_horizontal(keycode, vars);
	rotate_player(keycode, vars);
	return (0);
}

/**
 * @brief Main function to run all the mlx hooks,
 * 1. Key hook
 * 2. Exit hook
 * 3. Render hook
 * 4. Loop
 * 
 * @param vars Master game vars
 */
void	ctrl_run_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L, &key_input, vars);
	mlx_hook(vars->win, 17, 0, &success_exit, vars);
	mlx_hook(vars->win, 6, 1L << 6, &mouse_hook, vars);
	mlx_loop_hook(vars->mlx, &render_main, vars);
	mlx_loop(vars->mlx);
}
