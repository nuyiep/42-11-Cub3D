/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_store_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:23:37 by plau              #+#    #+#             */
/*   Updated: 2023/06/15 19:38:38 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Store map into a temporary char ** */
/* temp_map will include empty lines (if any) */
int	store_map(char *str, int k, char **temp_map)
{
	temp_map[k] = ft_strdup(str);
	k++;
	return (k);
}

/* Store map size y into struct */
void	store_map_size_y(t_vars *vars, char **temp_map)
{
	int		i;
	char	*temp_trim_str;

	i = 0;
	while (temp_map[i] != NULL)
	{
		temp_trim_str = ft_strtrim(temp_map[i], " \t\n");
		if (temp_trim_str[0] != '\0')
			vars->map.size.y++;
		free(temp_trim_str);
		i++;
	}
}

/* Malloc my map struct - preparing for padding spaces */
void	malloc_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map.map = malloc(sizeof(char *) * (vars->map.size.y + 1));
	while (i < vars->map.size.y)
	{
		vars->map.map[i] = malloc(sizeof(char) * (vars->map.size.x + 1));
		i++;
	}
	vars->map.map[i] = NULL;
}

/* Store temp map into map and if length is less than max pad with spaces */
void	store_final_map_pad_spaces(t_vars *vars, char **temp_map, int i, int j)
{
	vars->map.map[i][j] = temp_map[i][j];
	if (ft_strchr("NSWE10\n", temp_map[i][j]) == NULL)
		vars->map.map[i][j] = '_';
}

/* Pad empty postion within the map with spaces */
/* Minus 1 to map size x to get the total number of character */
void	pad_map_with_spaces(t_vars *vars, char **temp_map)
{
	int	i;
	int	j;
	int	len;

	malloc_map(vars);
	i = 0;
	while (i < vars->map.size.y)
	{
		len = ft_strlen(temp_map[i]);
		len--;
		j = 0;
		while (j < vars->map.size.x)
		{
			if (j < len && temp_map[i][j] != '\0')
				store_final_map_pad_spaces(vars, temp_map, i, j);
			else if (j == (vars->map.size.x - 1))
				vars->map.map[i][j] = '\n';
			else
				vars->map.map[i][j] = '_';
			j++;
		}
		vars->map.map[i][j] = '\0';
		i++;
	}
	ft_freesplit(temp_map);
}
