/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:19:26 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:53:44 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESC: erases data in n bytes of memory pointed to by s
	RETURN: void
	TESTS: -printing string after 1st byte erased -> print nothing
			-delete middle part, show other bytes still intact
*/
void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = (char *) s;
	while (n)
	{
		*c = 0;
		c++;
		n--;
	}
}

/* int	main(void)
{
	char str[] = "test";
	printf("%s\n", str);
	ft_bzero(str, 1);
	printf("%s\n", str);

	char str1[] = "test";
	printf("%s\n", str1);
	ft_bzero(&str1[2], 1);
	printf("%c\n", str1[0]);
	printf("%c\n", str1[1]);
	printf("%c\n", str1[2]);
	printf("%c\n", str1[3]);
} */
