/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:07:03 by plau              #+#    #+#             */
/*   Updated: 2023/06/17 18:08:27 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Wong's ft_strtrim */
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
