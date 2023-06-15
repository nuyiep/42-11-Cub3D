/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/15 18:48:10 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	**temp_map;

	init_vars(&vars);
	temp_map = valid_check_file_textures(argc, argv, &vars);
	map_checking(&vars, temp_map);
	print_map(vars.map.map);
	free_all(&vars);
	system("leaks -q cub3d");
	return (0);
}
