/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_separate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/12 21:08:15 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Split elements for North and East textures */
int	split_elements_north_east(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "NO") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.n_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.n_img.size.x, &vars->map.n_img.size.y);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		if ((vars->map.n_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid north element");
		vars->map.n_img.addr = mlx_get_data_addr(vars->map.n_img.ptr,
				&vars->map.n_img.bpp, &vars->map.n_img.line_len,
				&vars->map.n_img.endian);
		free(after_trim);
		x++;
	}
	if (ft_strcmp(split[0], "EA") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.e_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.e_img.size.x, &vars->map.e_img.size.y);
		ft_printf("AFTER TRIM: %s\n", after_trim);
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

/* Split elements for South and West textures */
int	split_elements_south_west(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "SO") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.s_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.s_img.size.x, &vars->map.s_img.size.y);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		if ((vars->map.s_img.ptr == NULL) || split[2] != NULL)
			utils_print_error_exit("Invalid south element");
		vars->map.s_img.addr = mlx_get_data_addr(vars->map.s_img.ptr,
				&vars->map.s_img.bpp, &vars->map.s_img.line_len,
				&vars->map.s_img.endian);
		free(after_trim);
		x++;
	}
	if (ft_strcmp(split[0], "WE") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		vars->map.w_img.ptr = mlx_xpm_file_to_image(vars->mlx,
				after_trim, &vars->map.w_img.size.x, &vars->map.w_img.size.y);
		ft_printf("AFTER TRIM: %s\n", after_trim);
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

/* Split elements for Floor and Ceiling */
int	split_elements_floor_ceiling(t_vars *vars, char *str, int x)
{
	char	**split;
	char	*after_trim;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "C") == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		vars->map.c_rgb.r = ft_atoi(split[0]);
		vars->map.c_rgb.g = ft_atoi(split[1]);
		vars->map.c_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		x++;
	}
	if (ft_strncmp(str, "F", 1) == 0)
	{
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		vars->map.f_rgb.r = ft_atoi(split[0]);
		vars->map.f_rgb.g = ft_atoi(split[1]);
		vars->map.f_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		x++;
	}
	ft_freesplit(split);
	return (x);
}

/* Split file content into 2 parts: N, S, W, E, C, F v map */
void	split_file_into_three_parts(char *file, t_vars *vars, int count,
				char **temp_map)
{
	int		fd;
	int		i;
	char	*str;
	int		x;
	int		k;

	fd = open(file, O_RDONLY);
	i = 0;
	x = 0;
	k = 0;
	while (i < count - 1)
	{
		str = get_next_line(fd);
		if (x == 6)
			x++;
		if (x < 6)
		{
			x = split_elements_north_east(vars, str, x);
			x = split_elements_south_west(vars, str, x);
			x = split_elements_floor_ceiling(vars, str, x);
		}
		if (x == 7)
			k = parse_store_map(str, k, temp_map);
		i++;
		free(str);
	}
	temp_map[k] = NULL;
	close(fd);
}
