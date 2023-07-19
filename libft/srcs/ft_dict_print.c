/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:13:06 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:52:05 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * function passed to ft_lstiter to print out the dictionary key value pairs
*/
void	ft_dict_print(void *arg)
{
	printf("key:[%s] value:[%s]\n", ((t_dict *)arg)->key,
		(char *)(((t_dict *)arg)->value));
}

// int	main(void)
// {
// 	t_dict test;
// 	char *str = malloc(2);
// 	str[0] = 'H';
// 	str[1] = 0;
// 	test.value = str;
// 	char key[] = "hey";
// 	test.key = key;
// 	ft_dict_print(&test);
// }
