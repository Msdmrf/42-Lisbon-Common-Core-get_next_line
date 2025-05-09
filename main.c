/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:36:51 by migusant          #+#    #+#             */
/*   Updated: 2025/04/27 13:29:59 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -Wall -Wextra -Werror get*.c main.c && ./a.out

#include "get_next_line.h"
/* File Input */
int main(void)
{
	int fd;
	// int fd2;
	char *line;
	// char *line2;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file.");
		return (1);
	}
	// fd2 = open("test.txt", O_RDONLY);
	// if (fd == -1)
	// {
	// 	perror("Error opening file.");
	// 	return (1);
	// }
	printf("----- Reading & Printing File Contents -----\n");
	while ((line = get_next_line(fd)) != NULL/*  && (line2 = get_next_line(fd2)) != NULL */)
	{
		printf("%s", line);
        // printf("%s%s", line, line2);
		free(line);
		// free(line2);
	}
	close(fd);
	// close(fd2);
	return (0);
}

// /* Terminal Input */
// int main(void)
// {
// 	char *line;
// 	// char *line2;

// 	while (1)
// 	{
// 		line = get_next_line(0);
// 		// line2 = get_next_line(0);
// 		if (!line/*  || !line2 */)
// 			break;
// 		printf("You wrote: %s", line);
// 		// printf("You wrote: %s", line2);
// 		free(line);
// 		// free(line2);
// 	}
// 	return (0);
// }
