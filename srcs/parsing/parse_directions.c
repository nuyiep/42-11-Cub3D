/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:37:55 by plau              #+#    #+#             */
/*   Updated: 2023/06/17 15:13:39 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Store North image pointer and address into struct */
int	split_elements_north(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "NO") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.n_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.n_img.size.x, &vars->map.n_img.size.y);
		if ((vars->map.n_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid north element");
		vars->map.n_img.addr = mlx_get_data_addr(vars->map.n_img.ptr,
				&vars->map.n_img.bpp, &vars->map.n_img.line_len,
				&vars->map.n_img.endian);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Store South image pointer and address into struct */
int	split_elements_south(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "SO") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.s_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.s_img.size.x, &vars->map.s_img.size.y);
		if ((vars->map.s_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid south element");
		vars->map.s_img.addr = mlx_get_data_addr(vars->map.s_img.ptr,
				&vars->map.s_img.bpp, &vars->map.s_img.line_len,
				&vars->map.s_img.endian);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Store East image pointer and address into struct */
int	split_elements_east(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "EA") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.e_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.e_img.size.x, &vars->map.e_img.size.y);
		if ((vars->map.e_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid east element");
		vars->map.e_img.addr = mlx_get_data_addr(vars->map.e_img.ptr,
				&vars->map.e_img.bpp, &vars->map.e_img.line_len,
				&vars->map.e_img.endian);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Store West image pointer and address into struct */
int	split_elements_west(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "WE") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.w_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.w_img.size.x, &vars->map.w_img.size.y);
		if ((vars->map.w_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid west element");
		vars->map.w_img.addr = mlx_get_data_addr(vars->map.w_img.ptr,
				&vars->map.w_img.bpp, &vars->map.w_img.line_len,
				&vars->map.w_img.endian);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}
