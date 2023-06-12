/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/12 16:27:08 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	**temp_map;

	init_vars(&vars);
	temp_map = valid_check_file(argc, argv, &vars);
	map_checking(&vars, temp_map);
	free_all(&vars);
	system("leaks -q cub3d");
	return (0);
}
