/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:33:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/18 11:25:04 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>//printf, readline#include <readline/readline.h>
# include <stdbool.h>//true, false
# include <stdlib.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define NOFILE "No such file or directory"
# define NOCMD "command not found"

extern int	g_exit_code;

void	error_fatal(char *error_msg, void *mem);
int		error_continue(const char *err_origin, const char *err_object,
			const char *cstm_err_descr, int cstm_exit_code);

#endif
