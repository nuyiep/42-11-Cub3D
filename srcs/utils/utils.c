/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/10 17:43:56 by plau             ###   ########.fr       */
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

	k = 0;
	count = 0;
	count = ft_strlen(str);
	while (str[k] != '\0')
	{
		if (str[k] == ' ' || str[k] == '\t' || str[k] =='\n')
			k++;
		else
			break ;
	}
	after_trim = malloc(sizeof(char) * count + 1);
	int	j = 0;
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
int	ft_count_lines(int fd, t_vars *vars)
{
	char	*str;
	int		count;

	str = "HELLO";
	count = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		count++;
		free(str);
	}
	vars->map.temp_map_total_line = count;
	return (count);
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
	while (vars->map.map[i] != NULL)
	{
		ft_printf("%s\n", vars->map.map[i]);
		i++;
	}
}
