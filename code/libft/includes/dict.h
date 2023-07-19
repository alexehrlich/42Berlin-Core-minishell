/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:04:44 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/16 11:15:20 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "../includes/libft.h"

typedef struct s_dict
{
	char	*key;
	void	*value;
}	t_dict;

typedef struct s_list	t_list;

void	ft_dict_node_del(void *arg);
void	ft_dict_print(void *arg);
void	*ft_dict_get_value(t_list *dict, char *key);
t_list	*ft_dict_get_node(t_list *dict, char *key);
void	ft_dict_modify_value(t_list *dict, char *key, void *new_value);
void	ft_dict_add_node(t_list **dict, char *key, void *value);
void	ft_dict_rm_node(t_list **dict, char *key);
char	**ft_dict_to_strarr(t_list *dict);
t_list	*ft_dict_from_strarr(char **arr);

#endif
