#include "../cub3d.h"

void	draw_player(t_vars *vars)
{
	t_dvector	pos;

	// double h_ratio = (double)WIN_H / (double)(MINI_S * MINI_PX);
	// double w_ratio = (double)WIN_W / (double)(MINI_S * MINI_PX);
	// pos.x = vars->player.pos.x / w_ratio;
	// pos.y = vars->player.pos.y / h_ratio;
	pos.x = MINI_S * MINI_PX / 2;
	pos.y = MINI_S * MINI_PX / 2;
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

void	draw_diagonal(t_vars *vars, t_dvector dir, t_dvector dest)
{
	t_dvector origin;
	t_vector	max;
	t_vector	min;
	// (void)dest;
	// (void)dir;
	// (void)vars;
	// int i = 0;

	min.y = vars->player.pos.y - (5 * MINI_PX) - 1;
	max.y = vars->player.pos.y + (5 * MINI_PX) + 1;
	min.x = vars->player.pos.x - (5 * MINI_PX) - 1;
	max.x = vars->player.pos.x + (5 * MINI_PX) + 1;

	origin.x = MINI_S * MINI_PX / 2;
	origin.y = MINI_S * MINI_PX / 2;
	printf("dest (%f, %f)\n", dest.x, dest.y);
	while (origin.x < (MINI_S * MINI_PX / 2 + (dest.x - min.x) * SCALE * MINI_PX))
	{
		origin.x += dir.x;
		origin.y += dir.y;
		my_mlx_pixel_put(vars->map.mini, (int)(origin.x), (int)origin.y, GREEN);
	}


}

void	draw_dir(t_vars *vars)
{
	t_dvector	pos;
	t_dvector	dir;

	// double h_ratio = (double)WIN_H / (double)(MINI_S * MINI_PX);
	// double w_ratio = (double)WIN_W / (double)(MINI_S * MINI_PX);
	// pos.x = vars->player.pos.x / w_ratio;
	// pos.y = vars->player.pos.y / h_ratio;
	pos.x = MINI_S * MINI_PX / 2;
	pos.y = MINI_S * MINI_PX / 2;
	dir.x = vars->player.dir.x;
	dir.y = vars->player.dir.y;
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 15 + pos.x), (int)(dir.y * 15 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 14 + pos.x), (int)(dir.y * 14 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 13 + pos.x), (int)(dir.y * 13 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 12 + pos.x), (int)(dir.y * 12 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 11 + pos.x), (int)(dir.y * 11 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 10 + pos.x), (int)(dir.y * 10 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 9 + pos.x), (int)(dir.y * 9 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 8 + pos.x), (int)(dir.y * 8 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 7 + pos.x), (int)(dir.y * 7 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 6 + pos.x), (int)(dir.y * 6 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 5 + pos.x), (int)(dir.y * 5 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 4 + pos.x), (int)(dir.y * 4 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 3 + pos.x), (int)(dir.y * 3 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 2 + pos.x), (int)(dir.y * 2 + pos.y), RED);
	my_mlx_pixel_put(vars->map.mini,  (int)(dir.x * 1 + pos.x), (int)(dir.y * 1 + pos.y), RED);
}

void	draw_plane(t_vars *vars)
{
	t_dvector	pos;
	t_dvector	plane;

	// double h_ratio = (double)WIN_H / (double)(MINI_S * MINI_PX);
	// double w_ratio = (double)WIN_W / (double)(MINI_S * MINI_PX);
	// pos.x = vars->player.pos.x / w_ratio;
	// pos.y = vars->player.pos.y / h_ratio;
	pos.x = MINI_S * MINI_PX / 2;
	pos.y = MINI_S * MINI_PX / 2;
	plane.x = vars->player.plane.x;
	plane.y = vars->player.plane.y;
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 15 + pos.x), (int)(plane.y * 15 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 14 + pos.x), (int)(plane.y * 14 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 13 + pos.x), (int)(plane.y * 13 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 12 + pos.x), (int)(plane.y * 12 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 11 + pos.x), (int)(plane.y * 11 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 10 + pos.x), (int)(plane.y * 10 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 9 + pos.x), (int)(plane.y * 9 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 8 + pos.x), (int)(plane.y * 8 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 7 + pos.x), (int)(plane.y * 7 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 6 + pos.x), (int)(plane.y * 6 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 5 + pos.x), (int)(plane.y * 5 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 4 + pos.x), (int)(plane.y * 4 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 3 + pos.x), (int)(plane.y * 3 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 2 + pos.x), (int)(plane.y * 2 + pos.y), GREEN);
	my_mlx_pixel_put(vars->map.mini,  (int)(plane.x * 1 + pos.x), (int)(plane.y * 1 + pos.y), GREEN);
}

void	colour_block(t_img *img, int start_x, int start_y, int size, int colour)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(img, start_x + x, start_y + y, colour);
			x++;
		}
		y++;
	}
}

// NEXT: Wall collision stop movement
void	draw_minimap(t_vars *vars)
{
	t_vector	cur;
	t_vector	max;
	t_vector	min;
	t_vector	scale;

	if (vars->map.mini->ptr != NULL)
		mlx_destroy_image(vars->mlx, vars->map.mini->ptr);
	vars->map.mini->ptr = mlx_new_image(vars->mlx, MINI_S * MINI_PX, MINI_S * MINI_PX);
	vars->map.mini->addr = mlx_get_data_addr(vars->map.mini->ptr,
				&vars->map.mini->bpp, &vars->map.mini->line_len, &vars->map.mini->endian);

	colour_block(vars->map.mini, 0, 0, MINI_S * MINI_PX, TGREY);

	min.y = vars->player.pos.y * MINI_PX - (5 * MINI_PX) - 1;
	max.y = vars->player.pos.y * MINI_PX + (5 * MINI_PX) + 1;
	min.x = vars->player.pos.x * MINI_PX - (5 * MINI_PX) - 1;
	max.x = vars->player.pos.x * MINI_PX + (5 * MINI_PX) + 1;

	cur.y = min.y;
	while (++cur.y < max.y)
	{
		cur.x = min.x;
		while (++cur.x < max.x)
		{
			int map_x = cur.x / MINI_PX;
			int map_y = cur.y / MINI_PX;
			scale.y = (cur.y - min.y) * SCALE;
			scale.x = (cur.x - min.x) * SCALE;

			if (map_x < 0 || map_y < 0 || map_x > (vars->map.size.x - 1) || map_y > (vars->map.size.y - 1))
				colour_block(vars->map.mini, scale.x, scale.y, MINI_PX * SCALE, TRANS);
			else if (vars->map.map[map_y][map_x] == '1')
				colour_block(vars->map.mini, scale.x, scale.y, MINI_PX * SCALE, LIGHTPURPLE);
				// my_mlx_pixel_put(vars->map.mini, cur.x - min.x, cur.y - min.y, BLUE);
			else
				colour_block(vars->map.mini, scale.x, scale.y, MINI_PX * SCALE, TWHITE);
				// my_mlx_pixel_put(vars->map.mini, cur.x - min.x, cur.y - min.y, TRANS);
		}
	}
}

void	render_minimap(t_vars *vars)
{
	draw_minimap(vars);
	draw_player(vars);
	draw_dir(vars);
	draw_plane(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->map.mini->ptr, 0, 0);
}