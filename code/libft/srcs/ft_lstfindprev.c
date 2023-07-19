/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindprev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:55:18 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:37:06 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * returns the prev node of node
 * NULL is returned in case of empty list or just 1 element
*/
t_list	*ft_lstfindprev(t_list *lst, t_list *node)
{
	if (!lst || lst == node)
		return (NULL);
	if (!node)
		return (ft_lstlast(lst));
	while (lst->next && lst->next != node)
		lst = lst->next;
	return (lst);
}

/* #include <stdio.h>

void	test(t_list **lst)
{
	int *j = malloc(sizeof(int));
	int *k = malloc(sizeof(int));
	int *l = malloc(sizeof(int));

	*j = 3;
	*k = 5;
	*l = 7;

	// t_list	*prev = ft_lstfindprev(*lst, NULL);
	// if (prev == NULL)
	// 	printf("NULL\n");
	// printf("%i\n", *(int *)prev->content);

	t_list *node_2 = ft_lstnew(j);
	// ft_lstadd_back(lst, node_2);
	ft_lst_insert_before(lst, NULL, node_2);

	// ft_lstremove(lst, node_2, NULL);
	// ft_lstremove(lst, *lst, NULL);
	t_list *node_3 = ft_lstnew(k);
	ft_lst_insert_before(lst, NULL, node_3);
	// ft_lstadd_back(lst, node_3);
}

void	print_list(void *arg)
{
	printf("%i\n", *(int *)arg);
}

int	main(void)
{
	t_list *lst = NULL;

	int *i = malloc(sizeof(int));


	*i = 1;
	
	t_list *node_1 = ft_lstnew(i);
	ft_lstadd_back(&lst, node_1);
	test(&lst);
	ft_lstiter(lst, print_list);
	return 0;
} */
