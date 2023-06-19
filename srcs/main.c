/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/19 15:15:37 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Main function for our program */
int	main(int argc, char **argv)
{
	t_vars	vars;
	char	**temp_map;

	init_vars(&vars);
	temp_map = valid_check_file_textures(argc, argv, &vars);
	map_checking(&vars, temp_map);
	print_map(vars.map.map);
	ctrl_run_hooks(&vars);
	free_all(&vars);
	return (0);
}
