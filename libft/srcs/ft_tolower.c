/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:45:21 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:09 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	behavior undefined if c not unsigned char value or EOF
*/
int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		c += 32;
		return (c);
	}
	return (c);
}
