/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:33:26 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/12 12:23:50 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "../libft/includes/libft.h"
# include <stdbool.h>
# include <signal.h>

//minishell
typedef struct data
{
	char				*line;
	t_list				*env_dict;
	t_list				*tokens;
	t_list				*commands;
	struct sigaction	sa;
	bool				is_child_minishell;
}	t_data;

//lexer
typedef enum token_types
{
	I_RED,
	O_RED,
	O_RED_APP,
	I_RED_HD,
	EQUALS,
	PIPE,
	WORD,
	DQUOTES,
	SQUOTES,
	PARAMETER,
	WHITESPACE,
	NONE
}	t_token_types;

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

//parser
typedef enum cmd_type
{
	BUILTIN,
	PATH,
}	t_cmd_type;

typedef struct file
{
	char			*path;
	int				fd;
	char			*herdoc_lim;
	t_token_types	open_mode;
}t_file;

typedef struct command
{
	t_list			*arguments;
	t_cmd_type		type;
	bool			has_in_pipe;
	bool			has_out_pipe;
	t_token_types	in_redir_type;
	t_token_types	out_redir_type;
	t_list			*inred_file;
	t_list			*outred_file;
}					t_command;

#endif
