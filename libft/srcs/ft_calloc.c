/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:48 by schuah            #+#    #+#             */
/*   Updated: 2022/09/29 11:01:25 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(nitems * size);
	if (output == NULL || size == SIZE_MAX)
		return (NULL);
	while (i < (nitems * size))
	{
		output[i] = 0;
		i++;
	}
	return ((void *)output);
}
