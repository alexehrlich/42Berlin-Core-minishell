/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:34:16 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:36 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMERTERS:
		lst: The address of a pointer to the first link of
		a list.
		new: The address of a pointer to the node to be
		added to the list.
	DESCRIPTION:
		Adds the node ’new’ at the end of the list
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		prev = ft_lstlast(*lst);
		prev->next = new;
	}
}
