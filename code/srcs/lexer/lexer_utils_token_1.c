/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_token_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:03:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/18 17:32:40 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_utils.h"

char	*redirection_token(char *line, size_t *i, t_token_types *type)
{
	if (!ft_strncmp(&line[*i], "<<", 2))
	{
		*i += 2;
		*type = I_RED_HD;
		return (ft_strdup("<<"));
	}
	else if (!ft_strncmp(&line[*i], ">>", 2))
	{
		*i += 2;
		*type = O_RED_APP;
		return (ft_strdup(">>"));
	}
	else if (line[*i] == '<')
	{
		(*i)++;
		*type = I_RED;
		return (ft_strdup("<"));
	}
	else
	{
		(*i)++;
		*type = O_RED;
		return (ft_strdup(">"));
	}
}

/**
 * increase token_begin by one to omit the $, the info is saved as the
 * token_type anyways
*/
char	*parameter_token(char *line, size_t *i, t_token_types *type,
			t_list *env_dict)
{
	char	*expanded_str;

	(*i)++;
	*type = PARAMETER;
	expanded_str = expand(line, i, env_dict);
	if (!ft_strcmp(expanded_str, "$"))
		*type = WORD;
	return (expanded_str);
}

/**
 * this function is called by scan_tokens either when a single or double
 * qoute is detected in the line from readline
 * -> token type is set to WORD
 * -> qoutes are removed
 * -> expansion happens in double quotes (no word splitting though)
 * -> unclosed quotes are not handled in the sense, that just everything
 * until the end of the line would be saved a single token
*/
char	*quote_token(char *line, size_t *i, t_token_types *type,
			t_list *env_dict)
{
	char	*token_str;
	char	*expansion;

	token_str = NULL;
	if (line[(*i)++] == '"')
		*type = DQUOTES;
	else
		*type = SQUOTES;
	while (*type == SQUOTES && line[*i] != '\'' && line[*i])
		token_str = append_str(token_str, char_to_str(line[(*i)++]));
	while (*type == DQUOTES && line[*i] != '"' && line[*i])
	{
		if (line[(*i)] == '$')
		{
			(*i)++;
			expansion = expand(line, i, env_dict);
			token_str = append_str(token_str, expansion);
		}
		else
			token_str = append_str(token_str, char_to_str(line[(*i)++]));
	}
	if (line[*i])
		(*i)++;
	*type = WORD;
	return (token_str);
}

char	*whitespace_token(char *line, size_t *i, t_token_types *type)
{
	size_t	token_begin;

	token_begin = *i;
	*type = WHITESPACE;
	while (is_whitespace(line[*i]) && line[*i])
		(*i)++;
	return (ft_substr(line, token_begin, *i - token_begin));
}

char	*pipe_token(size_t *i, t_token_types *type)
{
	*type = PIPE;
	(*i)++;
	return (ft_strdup("|"));
}
