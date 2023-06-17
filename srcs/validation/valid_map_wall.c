/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:29 by plau              #+#    #+#             */
/*   Updated: 2023/06/17 15:36:10 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Find map size x */
int	find_map_size_x(int temp_len, int max)
{
	if (temp_len > max)
		max = temp_len;
	return (max);
}

void	check_for_spaces(char **temp_map, int i, int j)
{
	if (ft_strchr("10NSWE", temp_map[i - 1][j]) == NULL
		|| ft_strchr("10NSWE", temp_map[i + 1][j]) == NULL
		|| ft_strchr("10NSWE", temp_map[i][j + 1]) == NULL
		|| ft_strchr("10NSWE", temp_map[i][j - 1]) == NULL
		)
		utils_print_error_exit("Map is not surrounded by wall");
}

/* Check whether the middle zeros are surrounded by ones */
/* up, down, left, right need to be surrounded by ones */
void	check_middle_zeros_surrounded_by_ones(t_vars *vars, char **temp_map)
{
	int	i;
	int	j;
	int	temp_len;
	int	max;

	i = 0;
	temp_len = 0;
	max = -1;
	while (i < vars->map.size.y)
	{
		j = 0;
		temp_len = ft_strlen(temp_map[i]);
		max = find_map_size_x(temp_len, max);
		while (j < (temp_len - 1))
		{
			if (temp_map[i][j] == '0' || temp_map[i][j] == 'N'
				|| temp_map[i][j] == 'S' || temp_map[i][j] == 'W'
				|| temp_map[i][j] == 'E')
				check_for_spaces(temp_map, i, j);
			j++;
		}
		i++;
	}
	vars->map.size.x = max;
}

/* If there is more than one N, S, W or E, exit the program */
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
			{
				if (count_player > 1)
					utils_print_error_exit("More than one player in the map");
			}
			j++;
		}
		i++;
	}
	if (count_player == 0)
		utils_print_error_exit("Need at least one player");
}

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
			if (ft_strchr("10NSWED \n", temp_map[i][j]) == NULL)
				utils_print_error_exit("Map contains invalid character");
			j++;
		}
		i++;
	}
}
