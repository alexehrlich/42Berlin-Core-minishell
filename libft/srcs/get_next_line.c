/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:47:27 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/12 16:10:04 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
-frees memory stored at pointers in case they are not NULL and returns NULL
-stash is set to 0, so it wont be freed multiple times
*/
static void	*gnl_free(char **stash, char *buffer, char *line)
{
	if (*stash)
	{
		free (*stash);
		*stash = 0;
	}
	if (buffer)
		free (buffer);
	if (line)
		free (line);
	return (NULL);
}

/*
-joins buffer and stash together and frees previous joined str
-for the first time smth is stored in stash substr is used
*/
static char	*gnl_join(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
		*stash = gnl_substr(buffer, 0, BUFFER_SIZE);
	else
	{
		temp = *stash;
		*stash = gnl_strjoin(*stash, buffer);
		free(temp);
	}
	return (*stash);
}

/*
-goes through stash and saves the new line contained in stash
in the newly allocated string line that is passed down to get_next_line
-returns NULL in case of errors
*/
static char	*gnl_save(char **stash)
{
	char	*line;
	size_t	line_len;
	size_t	stash_len_remain;
	char	*nl_idx;
	char	*temp;

	nl_idx = gnl_strchr(*stash, '\n');
	if (!nl_idx)
		stash_len_remain = 0;
	else
		stash_len_remain = gnl_strlen(nl_idx + 1);
	line_len = gnl_strlen(*stash) - stash_len_remain;
	line = gnl_substr(*stash, 0, line_len);
	temp = *stash;
	*stash = gnl_substr(*stash, line_len, stash_len_remain);
	free(temp);
	if (!*stash)
		return (gnl_free(stash, NULL, line));
	return (line);
}

/*
DESCRIPTION: -read file into buffer and save in stashuntil EOF or until
new line is found
-buffer is flushed before each new read, incase less than BUFFER_SZ is read
-buffer is freed before leaving parse function
PARAMETERS: -stash: adress of stash, so that malloced strs can be saved
RETURN: -NULL in case end of file is reached or str allocation fails
-returns return from save function
*/
static char	*gnl_parse(int fd, char **stash, char *buffer)
{
	ssize_t	read_ret;

	while (!gnl_strchr(buffer, '\n'))
	{
		gnl_memset(buffer, 0, BUFFER_SIZE);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (!read_ret && !gnl_strlen(*stash))
			return (gnl_free(stash, buffer, NULL));
		*stash = gnl_join(stash, buffer);
		if (!*stash)
			return (gnl_free(stash, buffer, NULL));
		if (read_ret < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (gnl_save(stash));
}

/*
DESCRIPTION: returns a line from a file descriptor (fd)
RETURN: read line for correct behavior, NULL if nothing else to read or error
-malloc buffer with BUFFER_SIZE+1 (space for null term.) and set bytes to 0
-return NULL in case of invalid fd/buffer size/read error -> buffer and stash
are freed
-otherwise return return from gnl_parse function
*/
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[1024];

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	gnl_memset(buffer, 0, BUFFER_SIZE + 1);
	if (fd > 1023 || fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (gnl_free(&stash[fd], buffer, NULL));
	return (gnl_parse(fd, &stash[fd], buffer));
}

/* 
#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	//printf("%s", argv[1]);
	if (argc < 2)
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	char *temp;

	
	while ((temp = get_next_line(fd)))
	{
		printf("%s", temp);
		free(temp);
	}
}
*/
