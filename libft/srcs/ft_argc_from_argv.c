/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_from_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:09:00 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/06 17:18:22 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * return the number <argc> of entries in a null terminated char **
 * array <argv>
*/
int	ft_argc_from_argv(const char **argv)
{
	int	argc;

	argc = 0;
	while (argv && *argv)
	{
		argv++;
		argc++;
	}
	return (argc);
}

// int	main(void)
// {
// 	char **argv;
// 	argv = malloc(sizeof(char *) * 4);
// 	argv[0] = ft_strdup("1");
// 	argv[1] = NULL;
// 	argv[2] = ft_strdup("3");
// 	argv[3] = NULL;
// 	printf("%d\n", ft_argc_from_argv((const char **)argv));
// }
