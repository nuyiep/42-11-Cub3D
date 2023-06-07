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
	ctrl_run_hooks();

	// Temporary testing
	{
		t_img img;

		img.ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
		img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len, &img.endian);

		my_mlx_pixel_put(&img, 10, 10, 230);
		mlx_put_image_to_window(vars->mlx, vars->win, img.ptr, 0, 0);

		mlx_loop(vars->mlx);
	}
	return (0);
}
