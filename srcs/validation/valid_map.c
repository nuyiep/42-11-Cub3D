/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/07/02 15:03:23 by plau             ###   ########.fr       */
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
	while (temp_map[vars->map.size.y - 1][i] != '\0')
	{
		if (ft_strchr("1 \n", temp_map[vars->map.size.y - 1][i]) == NULL)
			utils_print_error_exit("Map not surrounded by walls- last line");
		i++;
	}
}

/* Allocate memory and replace the string after trimmed */
char	*trim_from_back(int len, char *temp_map)
{
	char	*after_trim;
	int		i;

	i = 0;
	after_trim = malloc(sizeof(char) * (len + 2));
	while (i <= len)
	{
		after_trim[i] = temp_map[i];
		i++;
	}
	after_trim[i] = '\0';
	free(temp_map);
	return (after_trim);
}

char	**map_trim_spaces_newline_from_the_back(char **temp_map)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (temp_map[i] != NULL)
	{
		len = ft_strlen(temp_map[i]);
		len--;
		while (len > 0)
		{
			if (ft_strchr(" \n", temp_map[i][len]) == NULL)
			{
				temp_map[i] = trim_from_back(len, temp_map[i]);
				break ;
			}
			len--;
		}
		i++;
	}
	return (temp_map);
}

/* Main function for map checking 	*/
/* Rules:   						*/
/*   doesnt allow for tabs in the map */
/*	 doesnt allow duplicate textures	*/
/*	 rgb must in the format of 23,23,23 (no spaces in between) */
void	map_checking(t_vars *vars, char **temp_map)
{
	check_invalid_character(temp_map, vars);
	temp_map = get_map_trim_newline(vars, temp_map);
	check_only_one_player(temp_map);
	check_empty_lines(temp_map);
	temp_map = map_trim_spaces_newline_from_the_back(temp_map);
	store_map_size_x(vars, temp_map);
	check_first_and_last_line(vars, temp_map);
	check_first_and_last_char(temp_map);
	pad_map_with_spaces(vars, temp_map);
	check_middle_map_line(vars);
}
