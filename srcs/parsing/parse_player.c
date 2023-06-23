/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:32:58 by plau              #+#    #+#             */
/*   Updated: 2023/06/23 16:40:31 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Get player map position (x, y) */
/* Map postion starts calculating from 0 */
void	get_player_mpos(t_vars *vars)
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
			}
			j++;
		}
		i++;
	}
}


