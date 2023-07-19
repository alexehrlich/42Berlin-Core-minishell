/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:17:31 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:31:27 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * returns the entire dictionary node belonging to key
*/
t_list	*ft_dict_get_node(t_list *dict, char *key)
{
	t_dict	*item;

	if (!key)
		return (NULL);
	while (dict)
	{
		item = (t_dict *)dict->content;
		if (!ft_strcmp(item->key, key))
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}
