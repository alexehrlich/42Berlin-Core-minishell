/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:01 by aehrlich          #+#    #+#             */
/*   Updated: 2023/06/28 13:08:44 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_utils.h"

/*
	pipes are now on the stack and does not to be freed. After a fork
	the current process gets the pipe of the former process.
	The currents in pipe is the formers out pipe and has therefore
	to be copied in the currents inpipe. if the current has an outpipe
	it gets populated in the known way.
*/
void	set_pipes(t_command *command, int *in_pipe, int *out_pipe)
{
	if (command->has_in_pipe)
		ft_memcpy(in_pipe, out_pipe, 2 * sizeof(int));
	if (command->has_out_pipe)
		pipe(out_pipe);
}

/*
	pipes are initialized with -1. If they had been populated
	with vaild fd, they are other than -1 and have to be closed.
	@argument - pipe:	pipe to close possibly
*/
void	close_pipe(int pipe[2])
{
	if (pipe && pipe[0] != -1)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
}

/*
	pipes are initialized with -1, because we need to
	check if they have to be closed later. when they are passed
	to pipe() sys call, the get a free int as a fs.
	@argument - in_pipe:	pipe init
	@argument - out_pipe:	pipe init
*/
void	init_pipes(int *in_pipe, int *out_pipe)
{
	in_pipe[0] = -1;
	in_pipe[1] = -1;
	out_pipe[0] = -1;
	out_pipe[1] = -1;
}
