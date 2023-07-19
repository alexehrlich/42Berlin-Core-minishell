/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:56:18 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/11 12:43:39 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "../includes/lexer.h"
# include "../libft/includes/libft.h"

extern int	g_exit_code;

t_list		*ft_create_cmd_list(t_list *token_head);
t_cmd_type	ft_get_cmd_type(char *str);
void		ft_set_pipe(t_list **cmd_head, bool *is_first_word);
void		ft_set_input_redirection(t_list **token_head,
				t_list *cmd_head);
void		ft_set_output_redirection(t_list **token_head,
				t_list *cmd_head);
void		ft_set_words(t_list *token_head,
				t_list *cmd_head,
				bool *is_first_word);
bool		ft_is_redirection(t_token_types type);
#endif
