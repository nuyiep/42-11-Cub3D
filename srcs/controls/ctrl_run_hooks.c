#include "../cub3d.h"

t_bool	is_wall(t_vars *vars, t_dvector pos)
{
	t_vector mpos;

	mpos.x = (int)(round(pos.x));
	mpos.y = (int)(round(pos.y));
	// printf("pos: (%d, %d)\n", mpos.x, mpos.y);
	if (mpos.x >= 0 && mpos.x < vars->map.size.x
		&& mpos.y >= 0 && mpos.y < vars->map.size.y)
	{
		if (vars->map.map[mpos.y][mpos.x] == '1')
			return (TRUE);
		// if (vars->map.map[mpos.y][mpos.x] == 'D'
			// && vars->map.door_state == D_CLOSE)
			// return (1);
	}
	return (FALSE);
}

t_bool	check_front_collision(t_vars *vars, double dir)
{
	t_dvector	check_pos;
	double		steps;

	steps = 0.01;
	if (is_wall(vars, vars->player.pos))
	{
		check_pos.x = vars->player.pos.x + dir * vars->player.dir.x * MOV_SPD;
		check_pos.y = vars->player.pos.y + dir * vars->player.dir.y * MOV_SPD;
		if (!is_wall(vars, check_pos))
			return (FALSE);
		else
			return (TRUE);
	}
	else
	{
		while (steps < MOV_SPD)
		{
			check_pos.x = vars->player.pos.x + dir * vars->player.dir.x * steps;
			check_pos.y = vars->player.pos.y + dir * vars->player.dir.y * steps;
			if (is_wall(vars, check_pos))
				return (TRUE);
			steps += 0.01;
		}
	}
	return (FALSE);
}

t_bool	check_side_collision(t_vars *vars)
{
	t_dvector	check_pos;
	t_dvector	pdir;
	double		steps;

	pdir = vars->player.dir;
	steps = 0.01;
	while (steps < MOV_SPD)
	{
		check_pos.x = vars->player.pos.x + ((pdir.x * cos(-PI / 2) - pdir.y * sin(-PI / 2)) * steps);
		check_pos.y = vars->player.pos.y + ((pdir.x * cos(-PI / 2) + pdir.y * sin(-PI / 2)) * steps);
		if (is_wall(vars, check_pos))
			return (TRUE);
		steps += 0.01;
	}
	return (FALSE);
}

void	move_player_vertical(int keycode, t_vars *vars)
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
void	move_player_horizontal(int keycode, t_vars *vars)
{
	if (keycode == KEY_A && check_side_collision(vars) == FALSE)
	{
		vars->player.pos.x = vars->player.pos.x + (vars->player.dir.x * cos(-PI / 2) //
				- vars->player.dir.y * sin(-PI / 2)) * MOV_SPD;
		vars->player.pos.y = vars->player.pos.y + (vars->player.dir.y * cos(-PI / 2)
				+ vars->player.dir.x * sin(-PI / 2)) * MOV_SPD;
		
	}
	else if (keycode == KEY_D && check_side_collision(vars) == FALSE)
	{
		vars->player.pos.x = vars->player.pos.x + (vars->player.dir.x * cos(PI / 2)
				- vars->player.dir.y * sin(PI / 2) * (MOV_SPD));
		vars->player.pos.y = vars->player.pos.y + (vars->player.dir.y * cos(PI / 2)
				+ vars->player.dir.x * sin(PI / 2) * (MOV_SPD));
	}
}

void	rotate_player(int keycode, t_vars *vars)
{
	double plane_rotate;
	
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
 * @brief Executes functions according to key pressed. WASD and LEFT & RIGHT ARROW KEY 
 * 
 * @param keycode Keyboard keys represented as integer
 * @param vars Master game vars
 * @return int 
 */
static int	key_input(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		success_exit();

	move_player_vertical(keycode, vars);
	move_player_horizontal(keycode, vars);
	rotate_player(keycode, vars);
	return (0);
}

void	mouse_input(t_vars *vars)
{
	int x;
	int y;
	double rotate_spd;
	double plane_rotate;

	rotate_spd = PI / (double)(WIN_W / 2);
	mlx_mouse_get_pos(vars->win, &x, &y);
	vars->player.rotate = rotate_spd * x;
	plane_rotate = vars->player.rotate + (PI / 2);

	vars->player.dir.x = cos(vars->player.rotate);
	vars->player.dir.y = sin(vars->player.rotate);
	vars->player.plane.x = cos(plane_rotate);
	vars->player.plane.y = sin(plane_rotate);
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
	mlx_hook(vars->win, 2, 1L, &key_input, vars); // key hook
	mlx_hook(vars->win, 17, 0, &success_exit, vars); // exit hook
	mlx_loop_hook(vars->mlx, &render_main, vars); // render hook
	mlx_loop(vars->mlx);
}
