/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:47:56 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/19 11:46:56 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*gnl_memset(void *s, int c, size_t n)
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

size_t	gnl_strlen(const char *s)
{
	size_t	length;

	if (s == 0)
		return (0);
	length = 0;
	while (*s != 0)
	{
		length++;
		s++;
	}
	return (length);
}

/*
	-returns pointer to first occurence of c in s
	-character = byte 
	-returns pointer to matched char or NULL if not found
	-term. 0 is considered part of the string
	
	casting int c to unsigned char
*/
char	*gnl_strchr(const char *s, int c)
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

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		k;

	if (s1 == 0 || s2 == 0)
		return (0);
	ret = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (ret == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		ret[i] = s2[k];
		i++;
		k++;
	}
	ret[i] = 0;
	return (ret);
}

/*
	RETURN:
		The substring.
		NULL if the allocation fails.
	DESC:
		Allocates (with malloc(3)) and returns a substring
		from the string ’s’.
		The substring begins at index ’start’ and is of
		maximum size ’len’.
	PARAMS:
		s:  The string from which to create the substring.
		start:  The start index of the substring in the
		string ’s’.
		len:  The maximum length of the substring.
*/
char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (s == 0)
		return (0);
	s_len = gnl_strlen(s);
	i = 0;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
