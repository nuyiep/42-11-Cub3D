/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:29 by plau              #+#    #+#             */
/*   Updated: 2023/06/14 15:09:57 by plau             ###   ########.fr       */
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

void	check_for_spaces(t_vars *vars, int i, int j)
{
	if (ft_strchr("10NSWE", vars->map.map[i - 1][j]) == NULL
		|| ft_strchr("10NSWE", vars->map.map[i + 1][j]) == NULL
		|| ft_strchr("10NSWE", vars->map.map[i][j + 1]) == NULL
		|| ft_strchr("10NSWE", vars->map.map[i][j - 1]) == NULL
		)
		utils_print_error_exit("Map is not surrounded by wall");
}

/* Check whether the middle zeros are surrounded by ones */
/* up, down, left, right need to be surrounded by ones */
void	check_middle_zeros_surrounded_by_ones(t_vars *vars)
{
	int	i;
	int	j;
	int	temp_len;
	int	max;

	i = 1;
	temp_len = 0;
	max = -1;
	while (i < (vars->map.size.y - 1))
	{
		j = 1;
		temp_len = ft_strlen(vars->map.map[i]);
		max = find_map_size_x(temp_len, max);
		while (j < (temp_len - 1))
		{
			if (vars->map.map[i][j] == '0')
				check_for_spaces(vars, i, j);
			j++;
		}
		i++;
	}
	if (max == -1)
		utils_print_error_exit("Invalid map- map is seperated by empty line");
	else
		vars->map.size.x = max;
}
