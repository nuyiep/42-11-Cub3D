/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_separate_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:59 by plau              #+#    #+#             */
/*   Updated: 2023/06/07 20:24:19 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Main function to split elements */
void	split_elements(t_game *game, char *str)
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
