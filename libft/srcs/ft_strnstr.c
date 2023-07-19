/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:14:55 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//compares string with substring: returns 1 if equal
static int	ft_cmp(char *str, char *to_find)
{
	while (*str != 0 && *to_find != 0)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

/*
	-first occurrence of little in big, with len char searched
	-char after \0 are not searched
	-Return:	-little empty: big
				-no little in big: 0
				-pointer to first occ. of little
	-COMMENTS:
		*b == 7 forces segfault
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	l_len;

	b = (char *) big;
	l = (char *) little;
	l_len = ft_strlen(l);
	if (b == 0)
		*b = 7;
	if (*l == 0)
		return (b);
	if (len < l_len)
		return (0);
	while (*b != 0 && len >= l_len)
	{
		if (ft_cmp(b, l))
			return (b);
		b++;
		len--;
	}
	return (0);
}
/*
	TESTS:
	-substr empty
	-substr not in str
	-empty str
	-both empty

*/
/* #include <stdio.h>

int	main(void)
{
	char *s_strs[] = {"", "helloworldelow", "low"};
	printf("%s\n", (ft_strnstr(s_strs[1], s_strs[2], 5)));

	ft_strnstr(((void*)0), "fake", 3);
} */
