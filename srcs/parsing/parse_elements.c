/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/19 18:50:37 by plau             ###   ########.fr       */
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
		vars->map.c_rgb.r = ft_atoi(split[0]);
		vars->map.c_rgb.g = ft_atoi(split[1]);
		vars->map.c_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Store textures into struct */
int	store_textures(t_vars *vars, char *str, int x)
{
	if (x == 6)
		x++;
	if (x < 6)
	{
		x = split_elements_north(vars, str, x);
		x = split_elements_south(vars, str, x);
		x = split_elements_east(vars, str, x);
		x = split_elements_west(vars, str, x);
		x = split_elements_floor(vars, str, x);
		x = split_elements_ceiling(vars, str, x);
	}
	return (x);
}

/* Split elements to textures and temporary map */
void	split_elements(t_vars *vars, int count, int fd, char **temp_map)
{
	int		i;
	int		x;
	int		k;
	char	*str;
	int		check;

	i = 0;
	x = 0;
	k = 0;
	check = 0;
	while (i < count - 1)
	{
		str = get_next_line(fd);
		x = store_textures(vars, str, x);
		if (x == 7)
		{
			check = check_correct_order(str, check);
			k = store_temp_map(str, k, temp_map);
		}
		i++;
		free(str);
	}
	temp_map[k] = NULL;
	if (check == 0)
		utils_print_error_exit("Incorrect element");
}

/* Main function for parsing */
/* Split file content into 2 parts: N, S, W, E, C, F v map */
/* Parsing for textures & map */
/* Parsing rules set by our team:  */
/* 		[Direction textures] Don't allow spaces or tabs after textures */
/* 		[Floor & Ceiling] 	Don't allow tabs after F/C	*/
void	split_file_into_two_parts(char *file, t_vars *vars, int count,
				char **temp_map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	split_elements(vars, count, fd, temp_map);
	close(fd);
}
