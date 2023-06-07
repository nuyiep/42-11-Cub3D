/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/07 19:09:51 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Print error and exit the program */
void	utils_print_error_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	ft_printf("\n");
	exit(EXIT_FAILURE);
}

/* Trim space and tab */
char	*ft_trim_space_tab(char *str)
{
	int		i;
	int		k;
	char	*after_trim;
	int		count;

	i = 0;
	k = 0;
	count = 0;
	count = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	count = count - i;
	after_trim = malloc(sizeof(char) * count);
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			after_trim[k] = str[i];
			k++;
		}
		i++;
	}
	after_trim[k] = '\0';
	return (after_trim);
}

/* Count total number of lines in .cub file */
int	ft_count_lines(int fd)
{
	char	*str;
	int		count;

	str = "HELLO";
	count = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		count++;
	}
	return (count);
}
