/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:13 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:15 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESC: fills first n bytes of memory area (pointed to by s) with constant byte c
	RETURN: returns pointer to memory area
	TESTS: -
*/
void	*ft_memset(void *s, int c, size_t n)
{
	char	*addr;

	addr = (char *) s;
	while (n)
	{
		*addr = c;
		addr++;
		n--;
	}
	return ((char *) s);
}

/* int	main(void)
{
	char str[] = "test";
	printf("%s\n", str);
	memset(&str, 'c', 3);
	printf("%s\n", str);
} */
