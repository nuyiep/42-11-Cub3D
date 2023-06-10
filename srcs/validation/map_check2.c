/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:41:51 by plau              #+#    #+#             */
/*   Updated: 2023/06/10 17:58:07 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_map_trim_newline(t_vars *vars)
{
	char	**after_trim;
	int		i;
	int		k;

	i = 0;
	k = 0;
	after_trim = malloc(sizeof(char *) * (vars->map.size_before.x + 1));
	while (vars->map.map[i] != NULL)
	{
		if (ft_strlen(vars->map.map[i]) > 0)
		{
			after_trim[k] = ft_strdup(vars->map.map[i]);
			k++;
		}
		i++;
	}
	update_map(vars, after_trim);
	ft_printf("debug\n");
	print_map(vars);
	ft_printf("end of debugging\n");
	ft_freesplit(after_trim);
}
