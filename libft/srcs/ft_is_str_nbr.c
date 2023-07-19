/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:30:17 by lbaumann          #+#    #+#             */
/*   Updated: 2023/06/21 12:30:42 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * checks if arg is a number 
 * (a number can start with + or - followed by only digits)
 * @return true if a number, false if no number
*/
bool	ft_is_str_nbr(const char *arg)
{
	if (!arg)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false); 
		arg++;
	}
	return (true);
}
