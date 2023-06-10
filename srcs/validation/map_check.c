/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:00:50 by plau              #+#    #+#             */
/*   Updated: 2023/06/10 17:58:48 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Map can only contain 1, 0, N, S, W, E, D */
void	check_invalid_character(t_vars *vars)
{
	int		i;
	int		j;
	char	*after_trim;

	i = 0;
	while (vars->map.map[i] != NULL)
	{
		j = 0;
		after_trim = ft_strtrim(vars->map.map[i], " \t\n");
		while (after_trim[j] != '\0')
		{
			if (after_trim[j] != '1' && after_trim[j] != '0' 
				&& after_trim[j] != 'N' && after_trim[j] != 'S'
				&& after_trim[j] != 'W' && after_trim[j] != 'E'
				&& after_trim[j] != 'D')
					utils_print_error_exit("Map contains invalid character");
			j++;
		}
		i++;
		free(after_trim);
	}
}

/* Trim spaces, tabs and new lines */
void	get_map_trim_spaces_tabs(t_vars *vars)
{
	char	**after_trim;
	int		i;

	i = 0;
	after_trim = malloc(sizeof(char *) * (vars->map.size_before.x + 1));
	while (vars->map.map[i] != NULL)
	{
		after_trim[i] = ft_strtrim(vars->map.map[i], " \t\n" );
		i++;
	}
	after_trim[i] = NULL;
	
	update_map(vars, after_trim);
	print_map(vars);
	ft_freesplit(after_trim);
}

/* Other functions */

	/* Find first line for map */

	// int trim_start = 0;
	// int	trim_end = 0;

	// while (after_trim[trim_start] != NULL)
	// {
	// 	if (ft_strlen(after_trim[trim_start]) > 0)
	// 		break ;
	// 	trim_start++;
	// }
	// /* Find last line for map */
	// trim_end = vars->map.size_before.x;
	// while (trim_end >= i)
	// {
	// 	if (ft_strlen(after_trim[trim_end]) < 1)
	// 		break ;
	// 	trim_end--;
	// }

	// /* Start trimming \n */	
	// char **after_trim_2;

	// after_trim_2 = malloc(sizeof(char *) * (vars->map.size_before.x + 1));
	// i = 0;
	// while (trim_start <= trim_end)
	// {
	// 	after_trim_2[i] = after_trim[trim_start]; 
	// 	trim_start++;	
	// }
	// after_trim_2[i] = NULL;
	
	// /* Printing for testing */
	// ft_printf("Surrounded by walls check\n");
	// i = 0;
	// while (i < 5)
	// {
	// 	ft_printf("|%s|\n", after_trim_2[i]);
	// 	i++;
	// }
	// ft_printf("End\n");
	// /* End of printing for testing */
	
	// i = 0;
	// j = 0;
	// while (after_trim[i] != NULL)
	// {
	// 	while (after_trim[i][j] != '\0')
	// 	{
	// 		if (after_trim[i][j] != '1')
	// 			utils_print_error_exit("Map is not surrounded by walls [First line]");
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while (after_trim[i] != NULL)
	// {
	// 	if (after_trim[i][0] != '1')
	// 	{
	// 		ft_printf("after trim[i][0]: %c\n", after_trim[i][0]);
	// 		utils_print_error_exit("Map is not surrounded by walls [Left wall]");
	// 	}
	// 	i++;
	// }

	
	// i = 0;
    // while (after_trim[i] != NULL)
    // {
    //     free(after_trim[i]);
    //     i++;
    // }
    // free(after_trim);

/* Get map size before validation */
void	map_size_before_validation(t_vars *vars)
{
	while (vars->map.map[vars->map.size_before.x] != NULL)
		vars->map.size_before.x++;
}

void	map_checking(t_vars *vars)
{
	map_size_before_validation(vars);
	check_invalid_character(vars);
	get_map_trim_spaces_tabs(vars);
	//get_map_trim_newline(vars);
	// surrounded_by_walls(vars);
	// map_size_after_validation(vars);
}
