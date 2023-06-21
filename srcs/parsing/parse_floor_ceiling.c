/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:51:24 by plau              #+#    #+#             */
/*   Updated: 2023/06/21 15:28:04 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Split elements for Floor */
/* Store Floor RGB into struct */
int	split_elements_floor(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split_charset(str, " \t");
	if (ft_strcmp(split[0], "F") == 0)
	{
		check_extra_character(split);
		after_trim = ft_strtrim(split[1], " \t\n");
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		check_rgb_format(split);
		if (split[0] == NULL || split[1] == NULL || split[2] == NULL)
			utils_print_error_exit("Invalid floor");
		vars->map.f_rgb.r = ft_atoi(split[0]);
		vars->map.f_rgb.g = ft_atoi(split[1]);
		vars->map.f_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Split elements for Ceiling */
/* Store Ceiling RGB into struct */
int	split_elements_ceiling(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split_charset(str, " \t");
	if (ft_strcmp(split[0], "C") == 0)
	{
		check_extra_character(split);
		after_trim = ft_strtrim(split[1], " \t\n");
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		check_rgb_format(split);
		if (split[0] == NULL || split[1] == NULL || split[2] == NULL)
			utils_print_error_exit("Invalid ceiling");
		vars->map.c_rgb.r = ft_atoi(split[0]);
		vars->map.c_rgb.g = ft_atoi(split[1]);
		vars->map.c_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}
