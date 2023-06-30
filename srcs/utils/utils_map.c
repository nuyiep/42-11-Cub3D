/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:07:03 by plau              #+#    #+#             */
/*   Updated: 2023/06/30 11:45:19 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* In MLX, colours are presented in int format that contains the TRGB values */
/* Shift bits using the TRGB format */
/* T - transparency */
/* 0xTTRRGGBB format- 0x means that they are in hexa format */
/* T - 0 is opaque and 255 is fully transparent */
/* As the default background is black, fully transparent is black */
/* ft_printf("hex value: %08x\n", vars->map.f_rgb.hex) */
/* Bitshift formula is provided */
/* https://harm-smits.github.io/42docs/libs/minilibx/colors.html */
void	convert_rgb_to_hex(t_vars *vars)
{
	int	t;

	t = 0;
	vars->map.c_rgb.hex = t << 24 | vars->map.c_rgb.r << 16
		| vars->map.c_rgb.g << 8 | vars->map.c_rgb.b;
	vars->map.f_rgb.hex = t << 24 | vars->map.f_rgb.r << 16
		| vars->map.f_rgb.g << 8 | vars->map.f_rgb.b;
}

int	is_trimchar(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/* Trims character that appeared in char *set */
/* Trim the beginning and end */
/* Wong's ft_strtrim */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_trimchar(s1[start], set))
		start++;
	while (end && is_trimchar(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	trimstr = ft_substr(&s1[start], 0, end - start + 1);
	return (trimstr);
}

/* Print map for testing only */
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}
