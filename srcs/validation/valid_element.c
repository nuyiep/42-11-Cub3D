/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:06:53 by plau              #+#    #+#             */
/*   Updated: 2023/06/20 21:11:41 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Count total number of lines in .cub file */
int	ft_count_lines(int fd)
{
	char	*str;
	int		count;

	count = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	return (count + 1);
}

/* Check if rbg is digit and is between 0 - 255 */
void	check_rgb_format(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = ft_atoi(split[i]);
		if (j < 0 || j > 255)
			utils_print_error_exit("Invalid RGB format");
		i++;
	}
}

/* Check whether str (textures) contains extra characters  */
/* E.g. NO	./sprites/north.xpm x 				*/
/* char **split = NO	./sprites/north.xpm x   */
void	check_extra_character(char **split)
{
	int		i;
	char	*after_trim;
	int		count;

	i = 0;
	count = 0;
	while (split[i] != NULL)
	{
		after_trim = ft_strtrim(split[i], " \t\n");
		if (ft_strlen(after_trim) > 0)
			count++;
		free(after_trim);
		i++;
	}
	// if (count > 2)
	// {
	// 	ft_printf("split[0]: %s\n", split[0]);
	// 	ft_printf("split[1]: %s\n", split[1]);
	// 	utils_print_error_exit("Invalid element :|");
	// }
}
