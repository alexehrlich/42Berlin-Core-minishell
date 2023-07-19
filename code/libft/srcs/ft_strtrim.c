/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:08 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:04 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	checks if char c is contained in set s
	if contained 1 is returned
*/
static int	char_in_set(char c, char *set)
{
	while (*set != 0)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
	Parameters
		s1:  The string to be trimmed.
		set:  The reference set of characters to trim.
	Return value
		The trimmed string.
		NULL if the allocation fails.
	Description
		Allocates (with malloc(3)) and returns a copy of
		’s1’ with the characters specified in ’set’ removed
		from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_idx;
	int		end_idx;
	int		s1_len;
	int		i;
	char	*ret;

	if (s1 == 0 || set == 0)
		return (0);
	s1_len = ft_strlen(s1);
	start_idx = 0;
	end_idx = 0;
	i = 0;
	while (char_in_set((char) s1[i], (char *) set) && *s1 != 0)
	{
		start_idx++;
		i++;
	}
	while (char_in_set((char) s1[s1_len - 1], (char *) set) && s1_len > 0)
	{
		end_idx++;
		s1_len--;
	}
	s1_len = ft_strlen(s1);
	ret = ft_substr(s1, start_idx, s1_len - end_idx - start_idx);
	return (ret);
}
/* int main(void)
{
	char test[] = "aaabbbbtestbbaba";
	printf("%s\n", ft_strtrim(test, "ab"));
} */
