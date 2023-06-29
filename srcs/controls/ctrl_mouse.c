#include "../cub3d.h"

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
