/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_node_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:11:29 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:31:37 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * function passed to ft_lstremove, ft_lstclear, etc. to free dictionary data
*/
void	ft_dict_node_del(void *arg)
{
	t_dict	*data;

	if (!arg)
		return ;
	data = (t_dict *)arg;
	if (!data)
		return ;
	data->key = ft_free_set_null(data->key);
	data->value = ft_free_set_null(data->value);
	data = ft_free_set_null(data);
}
