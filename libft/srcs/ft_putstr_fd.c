/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:27:42 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 17:41:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Outputs the string ’s’ to the given file
	descriptor.
*/
int	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == 0)
		return (write(fd, "(null)", 6));
	s_len = ft_strlen(s);
	return (write(fd, s, s_len));
}
