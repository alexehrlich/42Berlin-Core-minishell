/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_to_strarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:14:32 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/16 11:42:20 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * converts the dictonary to a NULL terminated str arr
*/
char	**ft_dict_to_strarr(t_list *dict)
{
	char	**arr;
	char	**ret;
	char	*key_val_pair;
	char	*temp;
	t_dict	*node;

	arr = ft_calloc(sizeof(char *), (ft_lstsize(dict) + 1));
	if (!arr)
		return (NULL);
	ret = arr;
	while (dict)
	{
		node = (t_dict *)dict->content;
		temp = ft_strjoin(node->key, "=");
		key_val_pair = ft_strjoin(temp, node->value);
		free(temp);
		*arr = key_val_pair;
		dict = dict->next;
		arr++;
	}
	return (ret);
}
