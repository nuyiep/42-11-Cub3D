/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/20 12:57:37 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	store_nswefc(t_vars *vars, char *str, int x)
{
	x = split_elements_north(vars, str, x);
	x = split_elements_south(vars, str, x);
	x = split_elements_east(vars, str, x);
	x = split_elements_west(vars, str, x);
	x = split_elements_floor(vars, str, x);
	x = split_elements_ceiling(vars, str, x);
	return (x);
}

/* Store textures into struct */
int	store_textures(t_vars *vars, char *str, int x)
{
	if (vars->map.door_state == D_CLOSE)
	{
		if (x == 6)
			x++;
		if (x < 6)
			x = store_nswefc(vars, str, x);
	}
	else if (vars->map.door_state == D_OPEN)
	{
		if (x == 7)
			x++;
		if (x < 7)
		{
			x = store_nswefc(vars, str, x);
			x = split_elements_door(vars, str, x);
		}
	}
	return (x);
}

/* Split elements to textures and temporary map */
/* When there is no door in the map */
void	split_elements_without_door(t_vars *vars, int count,
									int fd, char **temp_map)
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

/* Split elements to textures and temporary map */
/* When there is door in the map */
void	split_elements_with_door(t_vars *vars, int count,
								int fd, char **temp_map)
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
		if (x == 8)
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
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (vars->map.door_state == D_OPEN)
		split_elements_with_door(vars, count, fd, temp_map);
	else if (vars->map.door_state == D_CLOSE)
		split_elements_without_door(vars, count, fd, temp_map);
	close(fd);
}
