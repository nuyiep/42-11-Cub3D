/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/29 17:47:57 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Print error and exit the program */
void	utils_print_error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	ft_printf("\n");
	system("leaks -q cub3d");
	exit(EXIT_FAILURE);
}

/* Free allocated memory */
void	free_all(t_vars *vars)
{
	ft_freesplit(vars->map.map);
	free(vars->map.main);
}

int	success_exit()
{
	system("leaks -q cub3d");
	exit(EXIT_SUCCESS);
	return (0);
}

/* Puts a pixel on the screen */
/* Formula is provided here */
/* https://harm-smits.github.io/42docs/libs/minilibx/pro
totypes.html#mlx_get_data_addr */
/* img->add: 			pointer to the start of the image data */
/* y * img->line_len:  	offset needed to skip y lines in the image */
/* x * img->bpp / 8:	offset needed to align with the correct column */
/*						in the image */
/*						img->bpp- the number of bits per pixel */
/*						by /8, we get the no of bytes per pixel */
/* dst:					memory add where the pixel's color value will be stored */
/* Assign color value to the memory add pointed by dst */
/* does so by casting dst to an unsigned int* (pointer to an unsigned integer) */
/* and then dereferencing it and assigning the color value */
/* Summary: calculates the memory add of a specific pixel in an image based */
/*			on its coordinates (x, y), and then sets the color value of that */
/* 			pixel at that memory */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
