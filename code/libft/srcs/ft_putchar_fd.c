/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:20:36 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 17:41:20 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMETERS:
		c: The character to output.
		fd: The file descriptor on which to write.
	DESCRIPTION:
		Outputs the character ’c’ to the given file
		descriptor.
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
