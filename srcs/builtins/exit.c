/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:39:50 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/17 09:25:53 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"

/**
 * return unsigned char 0-255
 * why do I even try to mimic the behaviour of bash???!!
 * numeric argument required has higher precedence than too many args
 * too many args does not exit the shell (but sets exit_code to 1)
 * exit is printed out even if the shell is not exited
 * numeric argument exit code: 2
 * exit without args exit code: 0
 * g_exit_code is updated before exit
 * never reaches last return statement
*/
int	builtin_exit(const char **argv, t_data *data)
{
	unsigned char	ret;
	int				argc;

	argc = ft_argc_from_argv(argv);
	ret = EXIT_SUCCESS;
	if (argc != 1 && !ft_is_str_nbr(argv[1]))
		ret = error_continue("exit", argv[1], "numeric argument required", 2);
	else if (argc > 2)
	{
		printf("exit\n");
		return (
			error_continue("exit", NULL, "too many arguments", EXIT_FAILURE)
		);
	}
	else if (argc != 1)
		ret = (unsigned char)ft_atoi(argv[1]);
	g_exit_code = ret;
	exit_gracefully(data);
	return (ret);
}
