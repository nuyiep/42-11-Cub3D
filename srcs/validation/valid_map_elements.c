/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:41:51 by plau              #+#    #+#             */
/*   Updated: 2023/06/21 17:49:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check whether the first element after the last texture is a valid map */
/* And that the string can only contain 1s */
int	check_correct_order(char *str, int check)
{
	int	i;

	i = 0;
	if (check != 0)
		return (check);
	str = ft_strtrim(str, " \t\n");
	if (ft_strlen(str) < 1)
	{
		free(str);
		return (check);
	}
	if (check == 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != '1' && str[i] != ' ' && str[i] != '\n'
				&& str[i] != '\t')
			{
				free(str);
				utils_print_error_exit("Invalid map/element");
			}
			i++;
		}
		check++;
	}
	free(str);
	return (check);
}

/* Get the first line of the map */
/* By triming that line (trim out) space, tabs and newline */
/* If the first character is \0, it is not the first line */
/* Do the same to the next line, until the first character is not \0 */
int	get_first_line(char **temp_map, int first_line)
{
	int		i;
	char	*temp_trim_str;

	i = 0;
	while (temp_map[i] != NULL)
	{
		temp_trim_str = ft_strtrim(temp_map[i], " \t\n");
		if (temp_trim_str[0] == '\0')
		{
			free(temp_trim_str);
			i++;
		}
		else
		{
			first_line = i;
			free(temp_trim_str);
			return (first_line);
		}
	}
	return (-1);
}

/* Get last line of map content */
/* Using the same logic as get_first_line */
/* Start checking from the last line of the temp_map */
int	get_last_line(char **temp_map, int last_line)
{
	int		i;
	int		count;
	char	*temp_trim_str;

	count = 0;
	while (temp_map[count] != NULL)
		count++;
	count--;
	i = 0;
	while (count > i)
	{
		temp_trim_str = ft_strtrim(temp_map[count], " \t\n");
		if (temp_trim_str[0] == '\0')
			free(temp_trim_str);
		else
		{
			last_line = count;
			free(temp_trim_str);
			return (last_line);
		}
		count--;
	}
	return (-2);
}

/* Save temp_map into new_temp_map */
/* temp_map 	-> only contains the map content with new lines before */
/* 					and after map content */
/* new_temp_map -> trims the newline before and after the map content  */
/* map struct 	->  is new_temp_map padded with spaces				   */
/* Save the total number of lines to vars->map.size.y */
char	**get_map_trim_newline(t_vars *vars, char **temp_map)
{
	int		i;
	char	**new_temp_map;
	int		first_line;
	int		last_line;

	first_line = 0;
	last_line = 0;
	first_line = get_first_line(temp_map, first_line);
	last_line = get_last_line(temp_map, last_line);
	vars->map.size.y = last_line - first_line + 1;
	new_temp_map = malloc(sizeof(char *) * (vars->map.size.y + 1));
	i = 0;
	while (first_line <= last_line)
	{
		new_temp_map[i] = ft_strdup(temp_map[first_line]);
		i++;
		first_line++;
	}
	new_temp_map[i] = NULL;
	ft_freesplit(temp_map);
	return (new_temp_map);
}

/* Check if there is empty lines within the map */
/* If there is empty lines, exit the program */
void	check_empty_lines(char **temp_map)
{
	int		i;
	int		len;
	char	*after_trim;

	i = 0;
	while (temp_map[i] != NULL)
	{
		after_trim = ft_strtrim(temp_map[i], " \t\n");
		len = ft_strlen(after_trim);
		free(after_trim);
		if (len == 0)
			utils_print_error_exit("Map contains empty line");
		i++;
	}
}
