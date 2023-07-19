/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:29 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:09 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESC: copies n bytes from address src to dest (area MUST NOT overlap)
	RETURN: pointer to dest
	TESTS: 
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dest;
	if (dest == 0 && src == 0)
		return (0);
	while (n)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}

/* #include <string.h>

int	main(void)
{
	char str[] = "test";
	char dst[5];

	printf("%s\n", str);
	//printf("%s\n", dst);
	ft_memcpy(dst, str, 5);
	printf("%s\n", str);
	printf("%s\n", dst);
} */
