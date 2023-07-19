/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:29:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMETERS:
		lst:  The address of a pointer to the first link of
		a list.
		new:  The address of a pointer to the node to be
		added to the list.
	DESCRIPTION:
		Adds the node ’new’ at the beginning of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0)
		return ;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

/* #include <stdio.h>

void printList(t_list *node)
{
	while (node != NULL)
	{
		printf(" %d ", *(int *)node->content);
		node = node->next;
	}
}

int main(void)
{
	t_list *head = 0;

	int i = 5;
	int j = 3;
	int k = 7;
	t_list *node_1 = ft_lstnew(&i);
	ft_lstadd_front(&head, node_1);
	t_list *node_2 = ft_lstnew(&j);
	ft_lstadd_front(&head, node_2);

	t_list *node_3 = ft_lstnew(&k);
	ft_lstadd_back(&head, node_3);

	ft_lstdelone(node_3, free);

	printf("size: %i\n", ft_lstsize(head));


	printf("\n Created Linked list is: ");
	printList(head);

	return 0;
} */
