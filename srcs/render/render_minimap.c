#include "../cub3d.h"

void	draw_player(t_vars *vars)
{
	t_dvector	pos;

	double h_ratio = (double)WIN_H / (double)(MINI_H * MINI_PX);
	double w_ratio = (double)WIN_W / (double)(MINI_W * MINI_PX);
	pos.x = vars->player.pos.x / w_ratio;
	pos.y = vars->player.pos.y / h_ratio;
	my_mlx_pixel_put(vars->map.mini,  pos.x - 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x + 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x - 1, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x + 1, pos.y, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x - 1, pos.y + 1, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x, pos.y + 1, GREEN);
	my_mlx_pixel_put(vars->map.mini,  pos.x + 1, pos.y + 1, GREEN);
}

void	draw_dir(t_vars *vars)
{
	t_dvector	pos;
	t_dvector	dir;

	double h_ratio = (double)WIN_H / (double)(MINI_H * MINI_PX);
	double w_ratio = (double)WIN_W / (double)(MINI_W * MINI_PX);
	pos.x = vars->player.pos.x / w_ratio;
	pos.y = vars->player.pos.y / h_ratio;
	dir.x = vars->player.dir.x;
	dir.y = vars->player.dir.y;
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.6 + pos.x, (int)dir.y * 0.6 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.5 + pos.x, (int)dir.y * 0.5 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.4 + pos.x, (int)dir.y * 0.4 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.3 + pos.x, (int)dir.y * 0.3 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.2 + pos.x, (int)dir.y * 0.2 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.1 + pos.x, (int)dir.y * 0.1 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.65 + pos.x, (int)dir.y * 0.65 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.55 + pos.x, (int)dir.y * 0.55 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.45 + pos.x, (int)dir.y * 0.45 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.35 + pos.x, (int)dir.y * 0.35 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.25 + pos.x, (int)dir.y * 0.25 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.15 + pos.x, (int)dir.y * 0.15 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.625 + pos.x, (int)dir.y * 0.625 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.525 + pos.x, (int)dir.y * 0.525 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.425 + pos.x, (int)dir.y * 0.425 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.325 + pos.x, (int)dir.y * 0.325 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.225 + pos.x, (int)dir.y * 0.225 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.125 + pos.x, (int)dir.y * 0.125 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.675 + pos.x, (int)dir.y * 0.675 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.575 + pos.x, (int)dir.y * 0.575 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.475 + pos.x, (int)dir.y * 0.475 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.375 + pos.x, (int)dir.y * 0.375 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.275 + pos.x, (int)dir.y * 0.275 + pos.y, RED);
	my_mlx_pixel_put(vars->map.mini,  (int)dir.x * 0.175 + pos.x, (int)dir.y * 0.175 + pos.y, RED);
}

void	create_minimap(t_vars *vars)
{
	if (vars->map.mini->ptr != NULL)
		mlx_destroy_image(vars->mlx, vars->map.mini->ptr);
	vars->map.mini->ptr = mlx_new_image(vars->mlx, MINI_W * MINI_PX, MINI_H * MINI_PX);
	vars->map.mini->addr = mlx_get_data_addr(vars->map.mini->ptr,
				&vars->map.mini->bpp, &vars->map.mini->line_len, &vars->map.mini->endian);
	
	int x;
	int y;

	y = -1;
	while (++y < MINI_H * MINI_PX)
	{
		x = -1;
		while (++x < MINI_W * MINI_PX)
		{
			my_mlx_pixel_put(vars->map.mini, x, y, TGREY);
		}
	}
}

void	generate_minimap(t_vars *vars)
{
	// create_map(vars);
	create_minimap(vars);
	draw_player(vars);
	draw_dir(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.mini->ptr, 0, 0);
}