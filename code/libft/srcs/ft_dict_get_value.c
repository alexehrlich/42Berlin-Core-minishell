/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:15:21 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:31:30 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * returns the pointer to the value corresponding to the key
 * @return pointer to value or NULL if either key is NULL, key not found,
 * or value is NULL
*/
void	*ft_dict_get_value(t_list *dict, char *key)
{
	t_dict	*item;

	if (!key)
		return (NULL);
	while (dict)
	{
		item = (t_dict *)dict->content;
		if (!ft_strcmp(item->key, key))
			return (item->value);
		dict = dict->next;
	}
	return (NULL);
}
