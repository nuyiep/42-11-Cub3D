/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_separate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/08 20:41:42 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Split elements for North and East textures */
void	split_elements_north_east(t_vars *vars, char *str)
{
	char	**split;
	char	*after_trim;

	if (ft_strncmp(str, "NO", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		// vars->map.n_img.ptr = mlx_xpm_file_to_image(vars->mlx, 
		// 	after_trim, &vars->map.n_img.size.x, &vars->map.n_img.size.y);
		// if (vars->map.n_img.ptr == NULL || split[2] != NULL)
		// 	utils_print_error_exit("Invalid north texture");
		// vars->map.n_img.addr = mlx_get_data_addr(vars->map.n_img.ptr, 
		// 	&vars->map.n_img.bpp, &vars->map.n_img.line_len, 
		// 	&vars->map.n_img.endian);
		free(after_trim);
		ft_freesplit(split);
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		free(after_trim);
		ft_freesplit(split);
	}
	(void)vars;
}

/* Split elements for South and West textures */
void	split_elements_south_west(t_vars *vars, char *str)
{
	char	**split;
	char	*after_trim;

	if (ft_strncmp(str, "SO", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		free(after_trim);
		ft_freesplit(split);
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		free(after_trim);
		ft_freesplit(split);
	}
	(void)vars;
}

/* Split elements for Floor and Ceiling */
void	split_elements_floor_ceiling(t_vars *vars, char *str)
{
	char	**split;
	char	*after_trim;

	if (ft_strncmp(str, "C", 1) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		vars->map.c_rgb.r = ft_atoi(split[0]);
		vars->map.c_rgb.g = ft_atoi(split[1]);
		vars->map.c_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		ft_freesplit(split);
	}
	if (ft_strncmp(str, "F", 1) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		ft_freesplit(split);
		split = ft_split(after_trim, ',');
		vars->map.f_rgb.r = ft_atoi(split[0]);
		vars->map.f_rgb.g = ft_atoi(split[1]);
		vars->map.f_rgb.b = ft_atoi(split[2]);
		free(after_trim);
		ft_freesplit(split);
	}
}

/* Split file content into 2 parts: N, S, W, E, C, F v map */
void	split_file_into_three_parts(char *file, t_vars *vars, int count)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < count - 1)
	{
		str = get_next_line(fd);
		split_elements_north_east(vars, str);
		split_elements_south_west(vars, str);
		split_elements_floor_ceiling(vars, str);
		free(str);
		i++;
	}
	close(fd);
}