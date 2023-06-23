/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/23 17:01:51 by plau             ###   ########.fr       */
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
	update_player(&vars);
	ft_printf("player char: %c\n", vars.player.char_dir);
	ft_printf("player map pos y: %d\n", vars.player.mpos.y);
	ft_printf("player map pos x: %d\n", vars.player.mpos.x);
	print_map(vars.map.map);
	// ctrl_run_hooks(&vars);
	free_all(&vars);
	system("leaks -q cub3d");
	return (0);
}
