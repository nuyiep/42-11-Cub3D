/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:35:16 by plau              #+#    #+#             */
/*   Updated: 2023/06/06 15:17:05 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	valid_check_argc_and_argc_format(int argc, char **argv)
{
	if (argc != 2)
		print_error_exit("Invalid number of arguments");
	(void)argv;	
}

void	valid_check_file(int argc, char **argv)
{
	valid_check_argc_and_argc_format(argc, argv);
	(void)argv;
}
