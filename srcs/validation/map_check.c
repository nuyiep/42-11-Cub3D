/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/06/12 16:42:47 by plau             ###   ########.fr       */
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

void	map_checking(t_vars *vars, char **temp_map)
{
	check_invalid_character(temp_map);
	get_map_trim_newline(vars, temp_map);
	// surrounded_by_walls(vars);
	// map_size_after_validation(vars);
}
