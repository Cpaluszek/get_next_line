/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:45:03 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/19 10:45:03 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *buffer);
static char	*ft_join_to_buffer(char *buffer, char *read);
static char	*ft_get_line(char *buffer);
static char	*ft_remove_current_line(char *buffer);

// NOTE ?: return error message
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_remove_current_line(buffer);
	return (line);
}

static char	*read_file(int fd, char *buffer)
{
	char	*content;
	size_t	byte_count;


	content = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (content == NULL)
		return (NULL);
	byte_count = 1;
	while (byte_count > 0)
	{
		byte_count = read(fd, content, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(content);
			return (NULL);
		}
		content[byte_count] = '\0';
		buffer = ft_join_to_buffer(buffer, content);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(content);
	return (buffer);
}

static char	*ft_join_to_buffer(char *buffer, char *read)
{
	char	*join;

	join = ft_strjoin(buffer, read);
	free(buffer);
	return (join);
}

// NOTE: check if first char is not '\0' ?
// NOTE: if eol is \0 or \n, replace eol by \n ?
static char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*ft_remove_current_line(char *buffer)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	remaining = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (remaining == NULL)
		return (NULL);
	free(buffer);
	return (remaining);
}
