/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:00:05 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMETERS:
		lst: The node to free.
		del: The address of the function used to delete
		the content.
	DESCIPTION:
		Takes as a parameter a node and frees the memory of
		the node’s content using the function ’del’ given
		as a parameter and free the node. The memory of
		’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == 0 || del == 0)
		return ;
	(*del)(lst->content);
	free(lst);
}
