/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_modify_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:19:21 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:36:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * searches dictionary entry belonging to key, frees the old value and replaces
 * it with new_value
*/
void	ft_dict_modify_value(t_list *dict, char *key, void *new_value)
{
	t_dict	*item;

	if (!key)
		return ;
	while (dict)
	{
		item = (t_dict *)dict->content;
		if (!ft_strcmp(item->key, key))
		{
			item->value = ft_free_set_null(item->value);
			item->value = new_value;
			return ;
		}
		dict = dict->next;
	}
}
