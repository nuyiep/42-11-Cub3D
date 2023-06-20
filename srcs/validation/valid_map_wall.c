/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:29 by plau              #+#    #+#             */
/*   Updated: 2023/06/20 16:21:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Reading in context: when map content is 0 or player pos (NSWE) */
/* check its up, down, left, right, if is not 10NSWE  */
/* print error and exit */
void	check_for_spaces(char **temp_map, int i, int j, t_vars *vars)
{
	if (vars->map.door_state == D_CLOSE)
	{
		if (ft_strchr("10NSWE", temp_map[i - 1][j]) == NULL
			|| ft_strchr("10NSWE", temp_map[i + 1][j]) == NULL
			|| ft_strchr("10NSWE", temp_map[i][j + 1]) == NULL
			|| ft_strchr("10NSWE", temp_map[i][j - 1]) == NULL
			)
			utils_print_error_exit("Map is not surrounded by wall");
	}
	else if (vars->map.door_state == D_OPEN)
	{
		if (ft_strchr("10NSWED", temp_map[i - 1][j]) == NULL
		|| ft_strchr("10NSWED", temp_map[i + 1][j]) == NULL
		|| ft_strchr("10NSWED", temp_map[i][j + 1]) == NULL
		|| ft_strchr("10NSWED", temp_map[i][j - 1]) == NULL
		)
			utils_print_error_exit("Map is not surrounded by wall");
	}
}

/* Check whether the middle zeros are surrounded by ones */
/* up, down, left, right need to be surrounded by ones */
void	check_middle_map_line(t_vars *vars, char **temp_map)
{
	int	i;
	int	j;
	int	temp_len;

	i = 0;
	temp_len = 0;
	while (i < vars->map.size.y)
	{
		j = 0;
		temp_len = ft_strlen(temp_map[i]);
		while (j < (temp_len - 1))
		{
			if (temp_map[i][j] == '0' || temp_map[i][j] == 'N'
				|| temp_map[i][j] == 'S' || temp_map[i][j] == 'W'
				|| temp_map[i][j] == 'E')
				check_for_spaces(temp_map, i, j, vars);
			j++;
		}
		i++;
	}
}

/* If there is more than one N, S, W or E, exit the program */
/* Store player direction in player struct */
void	check_only_one_player(t_vars *vars, char **temp_map)
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
			{
				vars->player.char_dir = temp_map[i][j];
				count_player++;
			}
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
