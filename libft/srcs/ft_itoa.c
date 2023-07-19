/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:44:31 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/12 16:10:15 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	calculates how many chars are needed for str allocation
*/
static int	chr_cnt(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		digits = 1;
	if (n == 0)
		digits = 1;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

/*
	saves number in str.
	memory needs to be set to 0 for this
*/
static void	ft_putnbr(int nb, char *s)
{
	char	c;

	if (nb < 0)
	{
		*s = '-';
		s++;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, s);
	}
	c = nb % 10 + '0';
	while (*s)
		s++;
	*s = c;
}

/*
	PARAMETERS:
		n: the integer to convert.
	RETURN:
		The string representing the integer.
		NULL if the allocation fails.
		malloc
	DESCRIPTION:
		Allocates (with malloc(3)) and returns a string
		representing the integer received as an argument.
		Negative numbers must be handle
*/
char	*ft_itoa(int n)
{
	int		digits;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = chr_cnt(n);
	ret = ft_calloc(digits + 1, 1);
	if (ret == 0)
		return (0);
	ft_putnbr(n, ret);
	return (ret);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
} */
