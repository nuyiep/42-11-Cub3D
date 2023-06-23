/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:32:58 by plau              #+#    #+#             */
/*   Updated: 2023/06/23 18:25:59 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Store player map position and direction character */
/* Map postion starts calculating from 0 */
void	store_player_mpos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.map[i] != NULL)
	{
		j = 0;
		while (vars->map.map[i][j] != '\0')
		{
			if (vars->map.map[i][j] == 'N' || vars->map.map[i][j] == 'S'
				|| vars->map.map[i][j] == 'W' || vars->map.map[i][j] == 'E')
			{
				vars->player.mpos.x = j;
				vars->player.mpos.y = i;
				vars->player.char_dir = vars->map.map[i][j];
			}
			j++;
		}
		i++;
	}
}

/* Store player direction (x, y) */
/* Store player plane (x, y) */
/* MLX's y-axis is inverted */ 
/* +ve y-axis represents downward movement */
/* -ve y-axis represents upward movement */
/* plane: field of view */
/* North, x is +ve */
/* South, x is -ve */
void	store_player_dir_north_south(t_vars *vars)
{
	if (vars->player.char_dir == 'N')
	{
		vars->player.dir.x = 0;
		vars->player.dir.y = -1;
		vars->player.plane.x = PLY_PLANE;
		vars->player.plane.y = 0;
	}
	else if (vars->player.char_dir == 'S')
	{
		vars->player.dir.x = 0;
		vars->player.dir.y = 1;
		vars->player.plane.x = -PLY_PLANE;
		vars->player.plane.y = 0;
	}
}

/* Store player direction (x, y) and player plane (x, y) */
void	store_player_dir_east_west(t_vars *vars)
{
	if (vars->player.char_dir == 'E')
	{
		vars->player.dir.x = 1;
		vars->player.dir.y = 0;
		vars->player.plane.x = 0;
		vars->player.plane.y = PLY_PLANE;
	}
	else if (vars->player.char_dir == 'W')
	{
		vars->player.dir.x = -1;
		vars->player.dir.y = 0;
		vars->player.plane.x = 0;
		vars->player.plane.y = -PLY_PLANE;
		ft_printf("did u enetxer\n");
		ft_printf("player dir x: %d\n", vars->player.dir.x);
		ft_printf("player dir y: %d\n", vars->player.dir.y);
	}
}

