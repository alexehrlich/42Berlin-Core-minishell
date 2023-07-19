/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:44:08 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:54 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMETERS:
		lst: The address of a pointer to a node.
		f: The address of the function used to iterate on
		the list.
		del: The address of the function used to delete
		the content of a node if needed.
	RETURNS:
		The new list.
		NULL if the allocation fails.
	DESCRIPTION:
		Iterates the list ’lst’ and applies the function
		’f’ on the content of each node. Creates a new
		list resulting of the successive applications of
		the function ’f’. The ’del’ function is used to
		delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	new_lst = 0;
	while (lst != 0)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == 0)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* #include <stdio.h>

void	*subtract(void *adr)
{
	*(int *)adr += 3;
	return (adr);
}

void printList(t_list *node)
{
	while (node != NULL)
	{
		printf(" %i ", *(int *)node->content);
		node = node->next;
	}
}

int main(void)
{
	t_list *head = 0;
	t_list *modified;

	int i = 5;
	int j = 3;
	int k = 7;
	t_list *node_1 = ft_lstnew(&i);
	ft_lstadd_front(&head, node_1);
	t_list *node_2 = ft_lstnew(&j);
	ft_lstadd_front(&head, node_2);

	t_list *node_3 = ft_lstnew(&k);
	ft_lstadd_back(&head, node_3);

	


	printf("\n Created Linked list is: ");
	printList(head);

	printf("modified list: ");
	modified = ft_lstmap(head, subtract, free);
	printList(modified);
	return 0;
} */
