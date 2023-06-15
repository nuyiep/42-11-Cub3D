#include "../cub3d.h"

void	move_player_vertical(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
	{
		vars->player.pos.y += (vars->player.dir.y * MOV_SPD);
		vars->player.pos.x += (vars->player.dir.x * MOV_SPD);
	}
	else if (keycode == KEY_S)
	{
		vars->player.pos.y -= (int)(vars->player.dir.y * MOV_SPD);
		vars->player.pos.x -= (int)(vars->player.dir.x * MOV_SPD);
	}
}

// Weird bug moving abit forward, not 100% horizontal
void	move_player_horizontal(int keycode, t_vars *vars)
{
	if (keycode == KEY_A)
	{
		vars->player.pos.x = vars->player.pos.x + (vars->player.dir.x * cos(-PI / 2) //
				- vars->player.dir.y * sin(-PI / 2) * (MOV_SPD));
		vars->player.pos.y = vars->player.pos.y + (vars->player.dir.y * cos(-PI / 2)
				+ vars->player.dir.x * sin(-PI / 2) * (MOV_SPD));
		
	}
	else if (keycode == KEY_D)
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
	(void)vars;
	if (keycode == KEY_ESC)
		success_exit();

	move_player_vertical(keycode, vars);
	move_player_horizontal(keycode, vars);
	vars->player.mpos.x = vars->player.pos.x / MINI_PX;
	vars->player.mpos.y = vars->player.pos.y / MINI_PX;
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
	mlx_hook(vars->win, 2, 1L, &key_input, vars); // key hook
	mlx_hook(vars->win, 17, 0, &success_exit, vars); // exit hook
	mlx_loop_hook(vars->mlx, &render_main, vars); // render hook
	mlx_loop(vars->mlx);
}
