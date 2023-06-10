/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:07:03 by plau              #+#    #+#             */
/*   Updated: 2023/06/10 17:55:45 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

/* Calculate the number of rows for after trim */
int	after_trim_rows(char **after_trim)
{
	int row;

	row = 0;
	while (after_trim[row] != NULL)
		row++;
	return (row);
}

/* Update map */
void	update_map(t_vars *vars, char **after_trim)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	row = after_trim_rows(after_trim);
	while (after_trim[i] != NULL)
	{
		free(vars->map.map[i]);
		vars->map.map[i] = ft_strdup(after_trim[i]);
		i++;
	}

	vars->map.map[i] = NULL;
}
