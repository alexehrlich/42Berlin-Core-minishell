/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:08:03 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 17:40:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
RET: 
	-printf should return total number of characters printed
	-negative value on error

*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_written;

	va_start(args, format);
	bytes_written = 0;
	if (!format)
		return (-1);
	if (ft_parser((char *) format, args, &bytes_written) < 0)
		return (-1);
	va_end(args);
	return (bytes_written);
}
