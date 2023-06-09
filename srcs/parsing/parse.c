/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:23:37 by plau              #+#    #+#             */
/*   Updated: 2023/06/09 18:41:32 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_invalid_map_element(char *str, int count, int i, int check_first)
{
	char *after_trim;
	
	ft_printf("DID YOU ENTER\n");
	if (check_first == 0)
	{
		if (str == NULL)
			utils_print_error_exit("Invalid map");
	}
	after_trim = ft_trim_space_tab_newline(str);
	if (str == NULL || ft_strlen(str) == 0)
	{
		ft_printf("zero\n");
		return ;
	}
	ft_printf("HERE:: |%s|\n", after_trim);
	free(after_trim);
	(void)count;
	(void)i;
}

int	parse_store_map(t_vars *vars, char *str, int k)
{
	int	y;

	y = ft_strlen(str);
	vars->map.map[k] = ft_strdup(str);
	ft_printf("map: |%s|", vars->map.map[k]);
	k++;
	return (k);
}
