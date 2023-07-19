/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:34:33 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/12 16:10:28 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	Outputs the integer ’n’ to the given file
	descriptor.
*/
int	ft_putnbr_fd(long n, int fd)
{
	char	c;
	int		bytes_written;

	bytes_written = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n == 0)
		return (write(fd, "0", 1));
	if (n < 0)
	{
		n *= -1;
		if (write(fd, "-", 1) < 0)
			return (-1);
		bytes_written++;
	}
	if (n > 9)
	{
		bytes_written += ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (++bytes_written);
}

/* int main(void)
{
	printf("\nbwritten: %i\n", ft_putnbr_fd(10, 1));
} */
