/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:30:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:06 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
