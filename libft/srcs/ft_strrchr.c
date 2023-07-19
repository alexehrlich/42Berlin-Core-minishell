/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:02:38 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:01 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESCRIPTION:
		The strrchr() function returns a pointer to the last  occurrence  of
		the character c in the string s.
	RETURN:
		strrchr() returns a pointer to the matched
		character or NULL if the character is not found. terminating
		null byte is considered part of the string, so that if c is speci‐
		ied as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	c = (unsigned char) c;
	len = ft_strlen(s);
	if (c == 0)
		return ((char *) &s[len]);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *) &s[len]);
		len--;
	}
	return (0);
}
