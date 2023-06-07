/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_separate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/07 20:42:58 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Main function to split elements for North and East textures */
void	split_elements_north_east(t_game *game, char *str)
{
	char	**split;

	if (ft_strncmp(str, "NO", 2) == 0)
	{
		split = ft_split(str, ' ');
		game->map.n_img.str = split[1];
		game->map.n_img.str = ft_trim_space_tab(game->map.n_img.str);
		ft_printf("|%s|\n", game->map.n_img.str);
		ft_freesplit(split);
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		split = ft_split(str, ' ');
		game->map.e_img.str = split[1];
		game->map.e_img.str = ft_trim_space_tab(game->map.e_img.str);
		ft_printf("|%s|\n", game->map.e_img.str);
		ft_freesplit(split);
	}
}

/* Main function to split elements for South and West textures */
void	split_elements_south_west(t_game *game, char *str)
{
	char	**split;

	if (ft_strncmp(str, "SO", 2) == 0)
	{
		split = ft_split(str, ' ');
		game->map.s_img.str = split[1];
		game->map.s_img.str = ft_trim_space_tab(game->map.s_img.str);
		ft_printf("|%s|\n", game->map.s_img.str);
		ft_freesplit(split);
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		split = ft_split(str, ' ');
		game->map.w_img.str = split[1];
		game->map.w_img.str = ft_trim_space_tab(game->map.w_img.str);
		ft_printf("|%s|\n", game->map.w_img.str);
		ft_freesplit(split);
	}
}

void	split_file_into_three_parts(char *file, t_game *game, int count)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < count - 1)
	{
		str = get_next_line(fd);
		split_elements_north_east(game, str);
		split_elements_south_west(game, str);
		i++;
	}
}
