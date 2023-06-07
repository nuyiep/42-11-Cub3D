/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:10 by plau              #+#    #+#             */
/*   Updated: 2023/06/06 15:20:22 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/**
 * @brief Prints out an error message with an optional [argument] befre EXITING program
 * 
 * @param str error message
 * @param arg optional argument
 */
void	print_error_exit(char *str, char *arg)
{
	ft_putstr_fd(str, 2);
	
	if (arg != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
