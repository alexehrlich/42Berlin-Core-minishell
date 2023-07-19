/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:03:26 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:47 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	DESCRIPTION: copies up to size - 1 characters to dest
			null terminate result as long as at size > 0
	USAGE: null should be included in size, src must be null terminated
	RETURN: length of string trying to create (length of src)
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (0 < (size - 1) && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (src_len);
}

/* int	main(void)
{
	char src1[] = "test";
	char dst1[5];

	printf("%s\n", src1);
	printf("%s\n", dst1);

	ft_strlcpy(dst1, src1, 2);

	printf("%s\n", src1);
	printf("%s\n", dst1);

} */