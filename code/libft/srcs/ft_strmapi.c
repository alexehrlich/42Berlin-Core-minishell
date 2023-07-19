/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:54:15 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:53 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	PARAMETERS:
		s: The string on which to iterate.
		f: The function to apply to each character.
		The string created from the successive applications
		of ’f’.
	RETURN:
		Returns NULL if the allocation fails.
		malloc
	DESCRIPTION
		Applies the function ’f’ to each character of the
		string ’s’, and passing its index as first argument
		to create a new string (with malloc(3)) resulting
		from successive applications of ’f’
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	char	*ret;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	str_len = ft_strlen(s);
	ret = malloc(str_len + 1);
	if (ret == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

/* char	test1(unsigned int i, char c)
{
	return c + i;
}

#include <stdio.h>

int	main(void)
{
	char s[] = "Hello";
	printf("original before: %s\n", s);
	printf("new after: %s\n", ft_strmapi(s, test1)); 
} */
