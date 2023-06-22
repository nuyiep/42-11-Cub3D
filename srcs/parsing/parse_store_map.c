/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_store_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:23:37 by plau              #+#    #+#             */
/*   Updated: 2023/06/22 15:15:40 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Store map into a temporary char ** */
/* temp_map will include all empty lines (if any) before and after map */
int	store_temp_map(char *str, int k, char **temp_map)
{
	temp_map[k] = ft_strdup(str);
	k++;
	return (k);
}

/* Store map size x */
void	store_map_size_x(t_vars *vars, char **temp_map)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	len = 0;
	max = -1;
	while (temp_map[i] != NULL)
	{
		len = ft_strlen(temp_map[i]);
		if (len > max)
			max = len;
		i++;
	}
	vars->map.size.x = max;
}

/* Malloc my map struct - preparing for padding spaces */
/* Allocate the maximum number of map.size.x for map  */
void	malloc_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map.map = malloc(sizeof(char *) * (vars->map.size.y + 1));
	while (i < vars->map.size.y)
	{
		vars->map.map[i] = malloc(sizeof(char) * (vars->map.size.x + 2));
		i++;
	}
	vars->map.map[i] = NULL;
}

/* Store temp map into map and if length is less than max pad with spaces */
void	store_final_map_pad_spaces(t_vars *vars, char **temp_map, int i, int j)
{
	vars->map.map[i][j] = temp_map[i][j];
	if (vars->map.door_state == D_OPEN)
	{
		if (ft_strchr("NSWE10D\n", temp_map[i][j]) == NULL)
			vars->map.map[i][j] = '_';
	}
	else if (vars->map.door_state == D_CLOSE)
	{
		if (ft_strchr("NSWE10\n", temp_map[i][j]) == NULL)
			vars->map.map[i][j] = '_';
	}
}

/* Pad empty postion within the map with spaces */
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
			if (j <= len && temp_map[i][j] != '\0')
				store_final_map_pad_spaces(vars, temp_map, i, j);
			else
				vars->map.map[i][j] = '_';
			j++;
		}
		vars->map.map[i][j] = '\n';
		vars->map.map[i][j + 1] = '\0';
		i++;
	}
	ft_freesplit(temp_map);
}
