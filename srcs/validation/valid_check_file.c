/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:35:16 by plau              #+#    #+#             */
/*   Updated: 2023/06/09 20:59:46 by plau             ###   ########.fr       */
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
void	valid_check_each_line(t_vars *vars, char *file)
{
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		utils_print_error_exit("Failed to open file");
	count = 0;
	count = ft_count_lines(fd, vars);
	vars->map.map = malloc(sizeof(char *) * (count + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	ft_printf("Total number of lines: %d\n", count);
	split_file_into_three_parts(file, vars, count);
}

/* Main function to check file */
void	valid_check_file(int argc, char **argv, t_vars *vars)
{
	valid_check_argc_and_argc_format(argc, argv);
	valid_check_each_line(vars, argv[1]);
}
