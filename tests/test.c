/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:24 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/18 20:39:59 by test_user        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*file_path;
	char	*output;
	int		fd;

	if (argc > 1)
		file_path = argv[1];
	fd = open(file_path, O_WRONLY);
	if (fd == -1)
	{
		printf("Can't open file : %s\n", file_path);
		return (-1);
	}
	else
		printf("file open on %d\n", fd);
	while (1)
	{
		output = get_next_line(fd);
		if (output == NULL)
			break ;
		printf("output = %s\n", output);
	}
	close(fd);
	return (0);
}
