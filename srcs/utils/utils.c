/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/12 16:54:36 by plau             ###   ########.fr       */
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

/* Trim space, tab and newline */
char	*ft_trim_space_tab_newline(char *str)
{
	int		k;
	char	*after_trim;
	int		count;
	int		j;

	k = 0;
	count = ft_strlen(str);
	while (str[k] != '\0')
	{
		if (str[k] == ' ' || str[k] == '\t' || str[k] == '\n')
			k++;
		else
			break ;
	}
	after_trim = malloc(sizeof(char) * count + 1);
	j = 0;
	while (str[k] != '\0')
	{
		if (str[k] != '\n')
		{
			after_trim[j] = str[k];
			j++;
		}
		k++;
	}
	after_trim[j] = '\0';
	return (after_trim);
}

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

void	free_all(t_vars *vars)
{
	ft_freesplit(vars->map.map);
	free(vars->map.main);
}

/* Print map */
void	print_map(t_vars *vars)
{
	int	i;

	i = 0;
	ft_printf("Start\n");
	while (vars->map.map[i] != NULL)
	{
		ft_printf("%s\n", vars->map.map[i]);
		i++;
	}
}
