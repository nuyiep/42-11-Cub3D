/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_separate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/09 20:51:09 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Split elements for North and East textures */
int	split_elements_north_east(t_vars *vars, char *str, int x)
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
		x++;
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		free(after_trim);
		ft_freesplit(split);
		x++;
	}
	(void)vars;
	return (x);
}

/* Split elements for South and West textures */
int	split_elements_south_west(t_vars *vars, char *str, int x)
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
		x++;
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		split = ft_split(str, ' ');
		after_trim = ft_trim_space_tab_newline(split[1]);
		ft_printf("AFTER TRIM: %s\n", after_trim);
		free(after_trim);
		ft_freesplit(split);
		x++;
	}
	return (x);
	(void)vars;
}

/* Split elements for Floor and Ceiling */
int	split_elements_floor_ceiling(t_vars *vars, char *str, int x)
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
		x++;
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
		x++;
	}
	return (x);
}

/* Split file content into 2 parts: N, S, W, E, C, F v map */
void	split_file_into_three_parts(char *file, t_vars *vars, int count)
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
			k = parse_store_map(vars, str, k);
		i++;
		free(str);
	}
	vars->map.map[k] = NULL;
	close(fd);
}
