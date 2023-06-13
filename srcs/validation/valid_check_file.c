/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:35:16 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 14:19:18 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check number of arguments, can only be 2 */
/* Check file format, can only be .cub */
void	valid_check_argc_and_argc_format(int argc, char **argv)
{
	if (argc != 2)
		utils_print_error_exit("Invalid number of arguments");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		utils_print_error_exit("Invalid file format");
}

/* Open file to check every line */
char	**valid_check_each_line(t_vars *vars, char *file)
{
	int		fd;
	int		temp_map_size_x;
	char	**temp_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		utils_print_error_exit("Failed to open file");
	temp_map_size_x = ft_count_lines(fd);
	temp_map = malloc(sizeof(char *) * (temp_map_size_x + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	split_file_into_three_parts(file, vars, temp_map_size_x, temp_map);
	return (temp_map);
}

void	check_all_textures_valid(t_vars *vars)
{
	if (vars->map.n_img.ptr == NULL || vars->map.s_img.ptr == NULL
		|| vars->map.w_img.ptr == NULL || vars->map.e_img.ptr == NULL)
		utils_print_error_exit("North/South/East/West not valid");
	if ((vars->map.c_rgb.r < 0 || vars->map.c_rgb.r > 255)
		|| (vars->map.c_rgb.g < 0 || vars->map.c_rgb.g > 255)
		|| (vars->map.c_rgb.b < 0 || vars->map.c_rgb.b > 255))
		utils_print_error_exit("Ceiling not valid");
	if ((vars->map.f_rgb.r < 0 || vars->map.f_rgb.r > 255)
		|| (vars->map.f_rgb.g < 0 || vars->map.f_rgb.g > 255)
		|| (vars->map.f_rgb.b < 0 || vars->map.f_rgb.b > 255))
		utils_print_error_exit("Floor not valid");
}

/* Main function to check file */
char	**valid_check_file(int argc, char **argv, t_vars *vars)
{
	char	**temp_map;

	valid_check_argc_and_argc_format(argc, argv);
	temp_map = valid_check_each_line(vars, argv[1]);
	check_all_textures_valid(vars);
	return (temp_map);
}
