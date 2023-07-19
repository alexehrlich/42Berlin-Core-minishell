/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:41:52 by lbaumann          #+#    #+#             */
/*   Updated: 2023/03/05 18:25:59 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
	returns len of substring until next delimeter c or until end of s
*/
static int	ft_substr_len(char *s, char c)
{
	int		len;

	len = 0;
	while (*s != 0 && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

/*
	count occurrences of delimiter c in s,
	delimiter multiple times in a row is counted as one
	delimiter in beginning and end of string dont count
*/
static int	ft_cnt_substr(char *s, char c)
{
	int		cnt_substr;
	int		i;
	int		flag;

	flag = 0;
	cnt_substr = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && flag == 0)
		{
			cnt_substr++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (cnt_substr);
}

/*
	Frees prev allocated memory in case malloc fails
*/
static void	ft_freemem(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_cpystrs(char *s, char c, char **arr, char *last_addr)
{
	int	word_len;

	while (s < last_addr)
	{
		word_len = ft_substr_len((char *)s, c);
		if (word_len != 0)
		{
			*arr = malloc(word_len + 1);
			if (*arr == 0)
			{
				ft_freemem(arr);
				return (0);
			}
			ft_strlcpy(*arr, (char *)s, word_len + 1);
			arr++;
		}
		s += word_len + 1;
	}
	*arr = 0;
	return (1);
}

/*
	PARAMETERS:
		s: The string to be split.
		c: The delimiter character.
	RETURNS:
		The array of new strings resulting from the split.
		NULL if the allocation fails.
	DESCRIPTION:
	Allocates (with malloc(3)) and returns an array
		of strings obtained by splitting ’s’ using the
		character ’c’ as a delimiter. The array must end
		with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	int		substrs;
	char	**arr;
	char	*last_addr;

	if (s == 0)
		return (0);
	substrs = ft_cnt_substr((char *)s, c);
	arr = malloc((substrs + 1) * sizeof(char *));
	if (arr == 0)
		return (0);
	last_addr = (char *)s + ft_strlen(s);
	if (!ft_cpystrs((char *)s, c, arr, last_addr))
		return (0);
	return (arr);
}

/* #include <stdio.h>

void    print_string_arr(char **arr)
{
    if(arr == 0)
    {
        printf("Empty arr\n");
        return;
    }
    printf("[");
    while(*arr != 0)
    {
        printf("%s, ", *arr);
        arr++;
    }
    printf("] \n");
}

int	main(void)
{
	//printf("%i\n", ft_cnt_delimiter("\0aa\0bbb", '\0'));
	//printf("%i\n", ft_cnt_substr("XHelloXXWorldX", 'X'));
	//printf("%i\n", ft_cnt_substr("XHalloXXorldX", 'X'));


	// char *s = "XXX";
	// print_string_arr(ft_split(s, 'X'));

	//ft_split
    // char delim = 'X';
	//print_string_arr(ft_split("XHelloXWorld", 'X'));
    //print_string_arr(ft_split("HelloXWorldX", 'X'));
    // print_string_arr(ft_split("HelloXWorld", 'X'));
    // print_string_arr(ft_split("XHello WorldX", 'X'));
    // print_string_arr(ft_split("NoDelimiter", 'X'));
    // print_string_arr(ft_split("Hello WorldX", 'X'));
    print_string_arr(ft_split(0, 'X'));
    // print_string_arr(ft_split("X", 'X'));
    // print_string_arr(ft_split("XX", 'X'));
    // print_string_arr(ft_split("XXX", 'X'));
    // print_string_arr(ft_split("", 'X'));
    // print_string_arr(ft_split(0, 'X'));
    // print_string_arr(ft_split("split  ||this|for|me|||||!|", '|'));


	//printf("len until next delim: %i\n", ft_substr_len(&str[1], 'c'));

	//ft_split(str, 'c');

	//printf("%li\n", sizeof(char *));
} */
