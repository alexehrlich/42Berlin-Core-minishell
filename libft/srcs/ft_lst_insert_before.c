/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:03:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:36:31 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * before: PREV-->NODE-->NEXT-->
 * after: -->PREV-->NEW-->NODE-->NEXT-->
*/
void	ft_lst_insert_before(t_list **lst, t_list *node, t_list *new)
{
	t_list	*prev;

	if (!new)
		return ;
	prev = ft_lstfindprev(*lst, node);
	if (prev)
		prev->next = new;
	else
		*lst = new;
	new->next = node;
}
