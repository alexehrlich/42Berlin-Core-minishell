/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_from_strarr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:12:52 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/13 15:06:10 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * convert dictionary to NULL terminated str array
 * the example str "var=" is saved in the dict with
 * an empty string "" as the value and the key "var"
*/
t_list	*ft_dict_from_strarr(char **arr)
{
	t_list	*dict;
	size_t	len;
	char	*key_val[2];
	char	*equals;

	dict = NULL;
	if (!arr)
		return (NULL);
	while (*arr)
	{
		equals = ft_strchr(*arr, '=');
		if (!equals)
			return (NULL);
		len = ft_strlen(*arr);
		key_val[0] = ft_substr(*arr, 0, equals - *arr);
		key_val[1] = ft_substr(equals + 1, 0, &(*arr)[len] - equals);
		if (!key_val[1])
			key_val[1] = ft_strdup("");
		ft_dict_add_node(&dict, key_val[0], key_val[1]);
		key_val[0] = ft_free_set_null(key_val[0]);
		arr++;
	}
	return (dict);
}
