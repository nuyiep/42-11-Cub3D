// #include "../cub3d.h"

// static void	draw_player(t_vars *vars)
// {
// 	t_vector	pos;

// 	pos.x = MINI_W * MINI_PX / 2;
// 	pos.y = MINI_H * MINI_PX / 2;
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x - 1, pos.y - 1, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x, pos.y - 1, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x + 1, pos.y - 1, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x - 1, pos.y, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x, pos.y, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x + 1, pos.y, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x - 1, pos.y + 1, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x, pos.y + 1, GREEN);
// 	mlx_pixel_put(vars->mlx, vars->win, pos.x + 1, pos.y + 1, GREEN);
// }

// void	generate_minimap(t_vars *vars)
// {
// 	create_map(vars);
// 	create_minimap(vars);
// 	draw_player(vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.mini->ptr, 0, 0);
// }