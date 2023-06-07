/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:25:14 by plau              #+#    #+#             */
/*   Updated: 2023/06/06 15:35:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// testing
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_vars *vars;

	vars = 0;

	valid_check_file(argc, argv);

	// Once all validation is done, start initalizing the game variables

	// Initialization below
	init_vars(vars);

	// Then, run all the hooks to start the mlx game
	ctrl_run_hooks(vars);

	// Temporary testing
	{
		t_img img;

		img.ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H); // this holds the space of the image
		img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len, &img.endian); // this holds the memory address of the the space

		my_mlx_pixel_put(&img, 10, 10, 230); // putting a pixel at x, y coordinate with color
		mlx_put_image_to_window(vars->mlx, vars->win, img.ptr, 0, 0); // then render the whole img to mlx window

		mlx_loop(vars->mlx);
	}
	return (0);
}
