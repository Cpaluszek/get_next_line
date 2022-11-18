/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:39:24 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/18 20:39:53 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

// TODO: return error message

// READ: if return 0 -> EOF
char	*get_next_line(int fd)
{
	char	*content;
	size_t	byte_count;
	
	if (fd == -1)
		return (NULL);
	content = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (content == NULL)
		return (NULL);
	byte_count = read(fd, content, BUFFER_SIZE);
	if (byte_count == -1)
		return (NULL);
	// TODO: split tring until next \n
	// Keep the remaining 
	// Recover remaining ? (strlcat ?)
	// realloc may be useful
	// return line
	return (content);
}
