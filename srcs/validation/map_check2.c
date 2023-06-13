/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:41:51 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 17:44:04 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Count temporary map lines */
int	count_temp_map_lines(char **temp_map)
{
	int	i;

	i = 0;
	while (temp_map[i] != NULL)
		i++;
	return (i);
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

/* Save temp_map into map struct */
/* Save the total number of lines to vars->map.size.y */
void	get_map_trim_newline(t_vars *vars, char **temp_map)
{
	int		i;
	int		k;
	char	*temp_trim_str;

	i = 0;
	store_map_size_y(vars, temp_map);
	vars->map.map = malloc(sizeof(char *) * (vars->map.size.y + 1));
	i = 0;
	k = 0;
	while (temp_map[i] != NULL)
	{
		temp_trim_str = ft_strtrim(temp_map[i], " \t\n");
		if (temp_trim_str[0] != '\0')
		{
			vars->map.map[k] = ft_strdup(temp_map[i]);
			k++;
		}
		free(temp_trim_str);
		i++;
	}
	vars->map.map[k] = NULL;
}
