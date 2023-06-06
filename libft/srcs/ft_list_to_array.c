/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:34:51 by schuah            #+#    #+#             */
/*   Updated: 2022/09/27 18:39:57 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_list_to_array(t_list *lst, int elem_size)
{
	void	*buffer;
	void	*head;

	if (lst == NULL)
		return (NULL);
	buffer = ft_calloc(ft_lstsize(lst), elem_size);
	head = buffer;
	while (lst != NULL)
	{
		ft_memcpy(buffer, lst->content, elem_size);
		lst = lst->next;
		buffer += elem_size;
	}
	return (head);
}
