/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:44 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	-returns pointer to first occurence of c in s
	-character = byte 
	-returns pointer to matched char or NULL if not found
	-term. 0 is considered part of the string
	
	casting int c to unsigned char
*/
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char) c;
	while (*s != 0)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *) s);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char test[] = "teste";
	printf("%p\n", test);

	char *res = ft_strchr(test, 357);
	printf("%p\n", res);
} */
