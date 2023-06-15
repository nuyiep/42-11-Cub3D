/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/06/14 17:12:04 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check whether the first and last line contains only of 1. */
/* Must contain 1 only. Only when 1 is present, spaces are allowed */
void	check_first_and_last_line(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map[0][i] != '\0')
	{
		if (ft_strchr("1 \n", vars->map.map[0][i]) == NULL)
			utils_print_error_exit("Map not surrounded by walls- first line");
		i++;
	}
	i = 0;
	while (vars->map.map[vars->map.size.y - 1][i] != '\0')
	{
		if (ft_strchr("1 \n", vars->map.map[vars->map.size.y - 1][i]) == NULL)
			utils_print_error_exit("Map not surrounded by walls- last line");
		i++;
	}
}

/* Check first and last character in the line - middle line in the map */
void	check_line_first_last_character(char *temp_after_trim)
{
	int	len;

	len = 0;
	if (temp_after_trim[0] != '1')
		utils_print_error_exit("Map not surrounded by wall- first character");
	len = ft_strlen(temp_after_trim);
	len--;
	if (temp_after_trim[len] != '1')
		utils_print_error_exit("Map not surrounded by wall- last character");
}

/* Check whether map is surrounded by walls (1) */
void	surrounded_by_walls(t_vars *vars)
{
	int		i;
	int		j;
	char	*temp_after_trim;

	i = 1;
	j = 0;
	check_first_and_last_line(vars);
	while (vars->map.map[i] != NULL)
	{
		j = 0;
		while (vars->map.map[i][j] != '\0')
		{
			temp_after_trim = ft_strtrim(vars->map.map[i], " \t\n");
			check_line_first_last_character(temp_after_trim);
			free(temp_after_trim);
			j++;
		}
		i++;
	}
	check_middle_zeros_surrounded_by_ones(vars);
}

/* Main function for map checking */
void	map_checking(t_vars *vars, char **temp_map)
{
	check_invalid_character(temp_map);
	get_map_trim_newline(vars, temp_map);
	check_only_one_player(vars);
	ft_freesplit(temp_map);
	surrounded_by_walls(vars);
	pad_map_with_spaces(vars);
}
