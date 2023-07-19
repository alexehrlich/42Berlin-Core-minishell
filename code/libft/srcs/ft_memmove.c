/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:52:19 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESC: copies n bytes from src to dest. areas maz overlap. first into temp 
			array, that is not overlapping
	RETURN: pointer to dest
	TESTS: -overlap with src addr smaller
			-overlap with dst adrr smaller
			-no overlap
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dest;
	if (dest == 0 && src == 0)
		return (0);
	while (n)
	{
		if (s < d)
			*(d + n - 1) = *(s + n - 1);
		else
		{
			*d = *s;
			s++;
			d++;
		}
		n--;
	}
	return (dest);
}

/* int	main(void)
{
	char str[5] = "test";
	char dst[5];
	printf("%s\n", str);
	//printf("%s\n", dst);
	//ft_memmove(&str[2], str, 5);
	//printf("%s\n", &str[2]);
	ft_memmove(dst, str, 5);
	printf("%s\n", dst);
}
 */
