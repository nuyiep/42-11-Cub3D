#include "../cub3d.h"

/**
 * @brief Main function to run all the mlx hooks,
 * 1. Key hook
 * 2. Exit hook
 * 3. Render hook
 * 4. Loop
 * 
 * @param vars 
 */
void	ctrl_run_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1, NULL, vars); // key hook
	mlx_hook(vars->win, 17, 0, NULL, vars); // exit hook
	mlx_loop_hook(vars->mlx, NULL, vars); // render hook
	mlx_loop(vars->mlx);
}
