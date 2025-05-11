/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:37:43 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 13:51:55 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	test_fd(int fd, const char *test_name)
{
	char	*line;
	int		line_count;

	if (fd < 0)
	{
		printf("\n%sError: Could not open file.\n", test_name);
		return;
	}
	printf("\n%s\n", test_name);
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_count++, line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	int	fd;

	// Test 1: Normal file with multiple lines
	fd = open("test_normal.txt", O_RDONLY);
	test_fd(fd, "--- Test 1 - Normal file ---");

	// Test 2: Empty file
	fd = open("test_empty.txt", O_RDONLY);
	test_fd(fd, "--- Test 2 - Empty file ---");

	// Test 3: One long line without newline
	fd = open("test_long.txt", O_RDONLY);
	test_fd(fd, "--- Test 3 - Long line ---");

	// Test 4: File with only newlines
	fd = open("test_newlines.txt", O_RDONLY);
	test_fd(fd, "\n--- Test 4 - Only newlines ---");

	// Test 5: Invalid fd
	test_fd(-1, "--- Test 5 - Invalid fd ---\n");

	// Test 6: Multiple file descriptors
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);

	char *line;
	printf("\n--- Test 6 - Multiple FDs Simultaneously ---\n");
	line = get_next_line(fd1);
	printf("fd1: %s", line);
	free(line);
	
	line = get_next_line(fd2);
	printf("fd2: %s", line);
	free(line);
	
	line = get_next_line(fd3);
	printf("fd3: %s", line);
	free(line);
	
	line = get_next_line(fd1);
	printf("fd1: %s", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);

	// Test 7: Standard input
	test_fd(0, "--- Test 7 - Standard input (type some lines, Ctrl+D to end) ---");
	
	return (0);
}