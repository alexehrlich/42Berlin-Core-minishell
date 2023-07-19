/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:02:37 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESCRIPTION:
		Allocates (with malloc(3)) and returns a new node.
		The member variable ’content’ is initialized with
		the value of the parameter ’content’.  The variable
		’next’ is initialized to NULL
	RETURN:
		the new node
	PARAMETERS:
		content:  The content to create the node with
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
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

int	main(void)
{
	t_list *test_list;
	int i = 6;
	printf("%p\n", &i);

	test_list = ft_lstnew(&i);

	printList(test_list);
	return (0);
} */