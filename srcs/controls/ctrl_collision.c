#include "../cub3d.h"

static t_bool	is_wall(t_vars *vars, t_dvector pos)
{
	t_vector mpos;

	mpos.x = (int)(round(pos.x));
	mpos.y = (int)(round(pos.y));
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
