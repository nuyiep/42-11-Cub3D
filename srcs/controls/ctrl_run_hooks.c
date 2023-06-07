#include "../cub3d.h"

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
		exit(EXIT_SUCCESS);

	move_player_vertical(keycode, vars);
	move_player_horizontal(keycode, vars);
	rotate_player(keycode, vars);
	return(0);
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
	mlx_hook(vars->win, 2, 1, &key_input, vars); // key hook
	mlx_hook(vars->win, 17, 0, NULL, vars); // exit hook
	mlx_loop_hook(vars->mlx, NULL, vars); // render hook
	mlx_loop(vars->mlx);
}
