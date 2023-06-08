#include "../cub3d.h"

void	draw_player(t_vars *vars)
{
	t_dvector	pos;

	pos.x = vars->player.pos.x;
	pos.y = vars->player.pos.y;
	my_mlx_pixel_put(&vars->player.img,  pos.x - 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x, pos.y - 1, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x + 1, pos.y - 1, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x - 1, pos.y, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x, pos.y, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x + 1, pos.y, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x - 1, pos.y + 1, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x, pos.y + 1, GREEN);
	my_mlx_pixel_put(&vars->player.img,  pos.x + 1, pos.y + 1, GREEN);
}

void	draw_dir(t_vars *vars)
{
	t_dvector	pos;
	t_dvector	dir;

	pos.x = vars->player.pos.x;
	pos.y = vars->player.pos.y;
	dir.x = vars->player.dir.x;
	dir.y = vars->player.dir.y;
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x + pos.x, (int)dir.y + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.9 + pos.x, (int)dir.y * 0.9 + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.8 + pos.x, (int)dir.y * 0.8 + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.7 + pos.x, (int)dir.y * 0.7 + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.6 + pos.x, (int)dir.y * 0.6 + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.5 + pos.x, (int)dir.y * 0.5 + pos.y, RED);
	my_mlx_pixel_put(&vars->player.img,  (int)dir.x * 0.4 + pos.x, (int)dir.y * 0.4 + pos.y, RED);
}

// void	generate_minimap(t_vars *vars)
// {
// 	create_map(vars);
// 	create_minimap(vars);
// 	draw_player(vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.mini->ptr, 0, 0);
// }