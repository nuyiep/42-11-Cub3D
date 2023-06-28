/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:29 by plau              #+#    #+#             */
/*   Updated: 2023/06/27 21:43:32 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* TODO: CHANGE _ BACK TO SPACE */
/* Reading in context: when map content is 0 or player pos (NSWE) or D */
/* check its up, down, left, right, if it is a space then is an error  */
/* print error and exit */
void	check_for_spaces(char **temp_map, int i, int j)
{
	if ((int)ft_strlen(temp_map[i - 1]) < j + 1
		|| (int)ft_strlen(temp_map[i + 1]) < j + 1
		|| temp_map[i + 1][j] == ' ' || temp_map[i - 1][j] == ' '
		|| temp_map[i][j + 1] == ' ' || temp_map[i][j - 1] == ' ')
		utils_print_error_exit("Map is not surrounded by wall");
}

/* Check whether the middle zeros are surrounded by ones */
/* up, down, left, right need to be surrounded by ones */
/* Skipped first and last line */
void	check_middle_map_line(t_vars *vars, char **temp_map)
{
	int		i;
	int		j;

	i = 1;
	while (i < (vars->map.size.y - 1))
	{
		j = 1;
		while (j < (vars->map.size.x - 1))
		{
			if (temp_map[i][j] == '0' || temp_map[i][j] == 'N'
				|| temp_map[i][j] == 'S' || temp_map[i][j] == 'W'
				|| temp_map[i][j] == 'E' || temp_map[i][j] == 'D')
				check_for_spaces(temp_map, i, j);
			j++;
		}
		i++;
	}
}

/* If there is more than one N, S, W or E, exit the program */
/* Store player direction in player struct */
void	check_only_one_player(char **temp_map)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (temp_map[i] != NULL)
	{
		j = 0;
		while (temp_map[i][j] != '\0' )
		{
			if (temp_map[i][j] == 'N' || temp_map[i][j] == 'S'
				|| temp_map[i][j] == 'W' || temp_map[i][j] == 'E')
				count_player++;
			if (count_player > 1)
				utils_print_error_exit("More than one player in the map");
			j++;
		}
		i++;
	}
	if (count_player == 0)
		utils_print_error_exit("Need at least one player");
}

/* Map can only contain 1, 0, N, S, W, E, D */
void	check_invalid_character(char **temp_map, t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (temp_map[i] != NULL)
	{
		j = 0;
		while (temp_map[i][j] != '\0')
		{
			if (vars->map.door_state == D_OPEN)
			{
				if (ft_strchr("10NSWED \n", temp_map[i][j]) == NULL)
					utils_print_error_exit("Map contains invalid character");
			}
			else if (vars->map.door_state == D_CLOSE)
			{
				if (ft_strchr("10NSWE \n", temp_map[i][j]) == NULL)
					utils_print_error_exit("Map contains invalid character");
			}
			j++;
		}
		i++;
	}
}

/* Checks the first character in each line whether is 1 */
void	check_first_and_last_char(char **temp_map)
{
	int		i;
	char	*copy_map_line;
	char	*after_trim;
	int		len;

	i = 0;
	while (temp_map[i] != NULL)
	{
		copy_map_line = ft_strdup(temp_map[i]);
		after_trim = ft_strtrim(copy_map_line, " ");
		len = ft_strlen(after_trim);
		if (len > 1)
		{
			if (ft_strchr("1\n ", after_trim[0]) == NULL)
				utils_print_error_exit(
					"Map is not surrounded by walls- first character");
			if (ft_strchr("1\n ", after_trim[len - 1]) == NULL)
				utils_print_error_exit(
					"Map is not surrounded by walls- last character");
		}
		free(after_trim);
		free(copy_map_line);
		i++;
	}
}
