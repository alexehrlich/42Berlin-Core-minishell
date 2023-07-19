/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:28:52 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:45 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	-size = full size of buffer
	-src and dst have to be NULL terminated
	-appends src at end of dst
	-appends at most size - strlen(dst) - 1 bytes
	-returns: initial length of dst + length of src
	-if traversed size characters without finding NULL, no NULL termination
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst != 0)
	{
		dst++;
		size--;
	}
	while ((size - 1) > 0 && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (dst_len + src_len);
}
