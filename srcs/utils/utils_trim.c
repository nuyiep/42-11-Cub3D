/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:07:03 by plau              #+#    #+#             */
/*   Updated: 2023/06/13 17:31:01 by plau             ###   ########.fr       */
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

/* Get the position of the first character that is not space, tabs */
/* and newline */
int	get_position_of_first_character(char *str, int k)
{
	while (str[k] != '\0')
	{
		if (str[k] == ' ' || str[k] == '\t' || str[k] == '\n')
			k++;
		else
			break ;
	}
	return (k);
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
	k = get_position_of_first_character(str, k);
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
