/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/17 18:07:31 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Print error and exit the program */
void	utils_print_error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	ft_printf("\n");
	exit(EXIT_FAILURE);
}

/* Free allocated memory */
void	free_all(t_vars *vars)
{
	ft_freesplit(vars->map.map);
	free(vars->map.main);
}
