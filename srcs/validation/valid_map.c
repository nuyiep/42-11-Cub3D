/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/06/17 18:58:12 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Needed so that the check_middle_map_lines will not enter the  */
/* 		check_for_spaces function and as there will not be any   */
/*		other characters other than 1s 							 */
/* Check whether the first and last line contains only of 1. */
/* Must contain 1 only. Only when 1 is present, spaces are allowed */
void	check_first_and_last_line(t_vars *vars, char **temp_map)
{
	int	i;

	i = 0;
	while (temp_map[0][i] != '\0')
	{
		if (ft_strchr("1 \n", temp_map[0][i]) == NULL)
			utils_print_error_exit("Map not surrounded by walls- first line");
		i++;
	}
	i = 0;
	while (temp_map[vars->map.size.y - 1][i] != '\0')
	{
		if (ft_strchr("1 \n", temp_map[vars->map.size.y - 1][i]) == NULL)
			utils_print_error_exit("Map not surrounded by walls- last line");
		i++;
	}
}

/* Check whether map is surrounded by walls (1) */
void	surrounded_by_walls(t_vars *vars, char **temp_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	check_first_and_last_line(vars, temp_map);
	check_middle_map_line(vars, temp_map);
}

/* Main function for map checking 	*/
/* Rules:   						*/
/* 	 our map allows for empty lines between map */
/*   doesnt allow for tabs after the last character */
void	map_checking(t_vars *vars, char **temp_map)
{
	check_invalid_character(temp_map);
	temp_map = get_map_trim_newline(vars, temp_map);
	check_only_one_player(temp_map);
	surrounded_by_walls(vars, temp_map);
	pad_map_with_spaces(vars, temp_map);
}
