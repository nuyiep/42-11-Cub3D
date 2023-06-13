/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 14:30:32 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Map can only contain 1, 0, N, S, W, E, D */
void	check_invalid_character(char **temp_map)
{
	int		i;
	int		j;

	i = 0;
	while (temp_map[i] != NULL)
	{
		j = 0;
		while (temp_map[i][j] != '\0')
		{
			if (ft_strchr("10NSWED \t\n", temp_map[i][j]) == NULL)
				utils_print_error_exit("Map contains invalid character");
			j++;
		}
		i++;
	}
}

/* If there is more than one N, S, W or E, exit the program */
void	check_only_one_player(t_vars *vars)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (vars->map.map[i] != NULL)
	{
		j = 0;
		while (vars->map.map[i][j] != '\0' )
		{
			if (vars->map.map[i][j] == 'N' || vars->map.map[i][j] == 'S'
				|| vars->map.map[i][j] == 'W' || vars->map.map[i][j] == 'E')
			{
				count_player++;
				if (count_player > 1)
					utils_print_error_exit("More than one player in the map");
			}
			j++;
		}
		i++;
	}
}

void	map_checking(t_vars *vars, char **temp_map)
{
	check_invalid_character(temp_map);
	get_map_trim_newline(vars, temp_map);
	check_only_one_player(vars);
	ft_freesplit(temp_map);
	// surrounded_by_walls(vars);
	// map_size_after_validation(vars);
}
