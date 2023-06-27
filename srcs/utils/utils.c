/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/27 19:23:44 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Print error and exit the program */
void	utils_print_error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	ft_printf("\n");
	// system("leaks -q cub3d");
	exit(EXIT_FAILURE);
}

/* Free allocated memory */
void	free_all(t_vars *vars)
{
	ft_freesplit(vars->map.map);
	free(vars->map.main);
}
/**
 * @brief Prints out an error message with an optional [argument] befre EXITING program
 * 
 * @param str error message
 * @param arg optional argument
 */
void	print_error_exit(char *str, char *arg)
{
	ft_putstr_fd(str, 2);
	
	if (arg != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	success_exit()
{
	exit(EXIT_SUCCESS);
	return (0);
}

/* Puts a pixel on the screen */
/* Divide by 8- */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
