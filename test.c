/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:24 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/16 11:59:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv)
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
	output = get_next_line(fd);
	printf("output = %s\n", output);
	return (0);
}
