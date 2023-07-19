/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:35:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/24 19:21:21 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
DESC:
	-loops through fromat string and writes each char
	-if format specifier % is detected ft_format is called with pointer of
	current argument and handles each case
	-bytes written is increased at adress for each char or with return
	from format
RET:
	-returns -1 in case write fails (return from format or putchar)
	-returns 0 in case of no failures
*/
int	ft_parser(char *format, va_list args, int *bytes_written)
{
	int	i;
	int	temp;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			temp = ft_format(&format[i], args);
			i++;
			if (temp < 0)
				return (-1);
			(*bytes_written) += temp;
		}
		else
		{
			if (ft_putchar_fd(format[i], 1) < 0)
				return (-1);
			(*bytes_written)++;
			i++;
		}
	}
	return (0);
}

/*
PARAMETERS: 
	-int *i: iterator from ft_parser

DESCRIPTION:
	-checks which conversion needs to be handled and calls the repectiveprinter
	functions
	-increases iterator i by one, so looping can continue in ft_parser
RETURN:
	-gets the number of chars printed from the printer functions
	and gives them back to ft_parser
	-on error returns -1
	-if none of the listed spefifiers is found -1 is returned
*/
int	ft_format(char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar_fd(va_arg(args, int), STD_OUT));
	else if (*format == 's')
		return (ft_putstr_fd(va_arg(args, char *), STD_OUT));
	else if (*format == 'p')
		return (ft_puthex_fd(va_arg(args, long), HEX_LC, STD_OUT, 1));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), STD_OUT));
	else if (*format == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), STD_OUT));
	else if (*format == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), HEX_UC, STD_OUT, 0));
	else if (*format == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), HEX_LC, STD_OUT, 0));
	else if (*format == '%')
		return (ft_putchar_fd('%', STD_OUT));
	else
		return (-1);
}
/*
DESC:
	prints number in hexadecimal system
PARAMS:
	-base: base for hex system: "0123456789abcdef" needs to be entered for
	correct function
	-is_ptr: if 1 -> null pointer printed in different format and 0x added
	before address
	-n is of type unsigned long, as it is needed for %p,%x,%X in printf
	therefore negative values are casted
RET:
	-bytes written
	-returns -1 if write fails
*/

int	ft_puthex_fd(size_t n, char *base, int fd, int is_ptr)
{
	int		bytes_written;
	int		index;

	bytes_written = 0;
	if (base == 0)
		return (0);
	if (is_ptr && n == 0)
		return (ft_putstr_fd("(nil)", fd));
	if (is_ptr)
	{
		is_ptr = 0;
		if (ft_putstr_fd("0x", fd) < 0)
			return (-1);
		bytes_written += 2;
	}
	if (n > 15)
	{
		bytes_written += ft_puthex_fd(n / 16, base, fd, is_ptr);
	}
	index = n % 16;
	if (write(fd, &base[index], 1) < 0)
		return (-1);
	return (++bytes_written);
}
