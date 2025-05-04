/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:54:57 by mda-enca          #+#    #+#             */
/*   Updated: 2025/05/03 12:36:27 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	main(void)
{
	char	*line;
	int		i;
	int		equal;
	//int		fd1;
	int		fd2;
	//int		fd3;
	//fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("banana.txt", O_RDONLY);
	//fd3 = open("tests/never.txt", O_RDONLY);
	i = 1;
	while (i < 1)
	{
		line = get_next_line(fd2);
		printf("%s \n", line);
		free(line);
		i++;
	}
	printf("\n");
	close(fd2);
	equal = 210;
	while (equal--)
		printf("=");
	printf("\n\n\n");
	// i = 1;
	// while (i < 55)
	// {
	// 	line = get_next_line(fd3);
	// 	printf("%s \n", line);
	// 	free(line);
	// 	i++;
	// }
	// close(fd3);
	return (0);
}
