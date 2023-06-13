/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:23:37 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 16:46:08 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check whether the first element after the last texture is a valid map */
/* Only contain 1 */
int	check_correct_order(char *str, int check)
{
	int	i;

	i = 0;
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

/* Store map into a temporary char ** */
/* temp_map will include empty lines (if any) */
int	store_map(char *str, int k, char **temp_map)
{
	temp_map[k] = ft_strdup(str);
	k++;
	return (k);
}
