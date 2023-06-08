/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:14 by zwong             #+#    #+#             */
/*   Updated: 2023/06/08 19:25:38 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render_main(t_vars *vars)
{
	// t_img	*img;

	// img = malloc(sizeof(t_img));
	// img = &vars->player.img;
	mlx_clear_window(vars->mlx, vars->win);
	// img->ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	// img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, &img->endian); // this holds the memory address of the the space
	generate_minimap(vars);
	
	// mlx_put_image_to_window(vars->mlx, vars->win, img->ptr, 0, 0); // then render the whole img to mlx window
	
	return (0);
}