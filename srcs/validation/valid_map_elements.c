/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:41:51 by plau              #+#    #+#             */
/*   Updated: 2023/06/15 15:49:09 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check whether the first element after the last texture is a valid map */
/* Only contain 1 */
int	check_correct_order(char *str, int check)
{
	int	i;

	i = 0;
	if (check != 0)
		return (check);
	str = ft_trim_space_tab_newline(str);
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
				utils_print_error_exit("Invalid map");
			i++;
		}
		check++;
	}
	free(str);
	return (check);
}

/* Save temp_map into map struct */
/* Save the total number of lines to vars->map.size.y */
char	**get_map_trim_newline(t_vars *vars, char **temp_map)
{
	int		i;
	int		k;
	char	*temp_trim_str;
	char	**new_temp_map;

	i = 0;
	store_map_size_y(vars, temp_map);
	new_temp_map = malloc(sizeof(char *) * (vars->map.size.y + 1));
	i = 0;
	k = 0;
	while (temp_map[i] != NULL)
	{
		temp_trim_str = ft_strtrim(temp_map[i], " \t\n");
		if (temp_trim_str[0] != '\0')
		{
			new_temp_map[k] = ft_strdup(temp_map[i]);
			k++;
		}
		free(temp_trim_str);
		i++;
	}
	new_temp_map[k] = NULL;
	ft_freesplit(temp_map);
	return (new_temp_map);
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
			{
				count_player++;
				if (count_player > 1)
					utils_print_error_exit("More than one player in the map");
				if (count_player < 1)
					utils_print_error_exit("Need at least one player");
			}
			j++;
		}
		i++;
	}
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
