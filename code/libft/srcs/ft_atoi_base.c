/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:16:50 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/24 20:22:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * converts the number encoded in base format to an integer
 * returns 0 on error
 * @param str str that should be converted to int
 * @param base what base system is used (base10: 0123456789 binary: 01, etc.)
*/
int	ft_atoi_base(const char *str, char *base)
{
	int	num;
	int	sign;
	int	baselen;
	int	idx;

	baselen = ft_strlen(base);
	num = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	idx = ft_chrstr(*str, base);
	while (idx + 1)
	{
		num = baselen * num + idx;
		str++;
		idx = ft_chrstr(*str, base);
	}
	num *= sign;
	return (num);
}
