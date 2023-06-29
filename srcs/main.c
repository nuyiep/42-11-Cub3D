/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/29 17:45:34 by plau             ###   ########.fr       */
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
	convert_rgb_to_hex(&vars);
	ctrl_run_hooks(&vars);
	ft_printf("here\n");
	free_all(&vars);
	return (0);
}
