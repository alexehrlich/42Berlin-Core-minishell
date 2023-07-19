/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:24:53 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:41 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ret;
	char	*ret_start;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	if (ret == 0)
		return (0);
	ret_start = ret;
	while (*s1 != 0)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	ft_strlcpy(ret, s2, len2 + 1);
	return (ret_start);
}
