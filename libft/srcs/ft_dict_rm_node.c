/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_rm_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:24:27 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/15 11:36:45 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"

/**
 * removes node corresponding to key from dictionary
*/
void	ft_dict_rm_node(t_list **dict, char *key)
{
	t_list	*node;

	node = ft_dict_get_node(*dict, key);
	ft_lstremove(dict, node, ft_dict_node_del);
}
