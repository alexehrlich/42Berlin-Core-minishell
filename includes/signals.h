/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:32:52 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/13 12:31:26 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "types.h"

void	handle_signals(int signal);
void	init_signals(t_data *data, void (*handle)(int));
void	ignore_sigint(int signal);
void	ignore_sigint_childshell(int signal);

#endif