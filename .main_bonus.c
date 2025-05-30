/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:41:56 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 12:18:52 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

// clear && cc get_next_line_bonus.c get_next_line_utils_bonus.c .main_bonus.c && valgrind --leak-check=full ./a.out || cat -e

void	test_single_fd(int fd, const char *test_name)
{
	char	*line;
	int		count;

	printf("\n%s\n", test_name);
	if (fd < 0)
	{
		printf("Error: Could not open file.\n");
		return ;
	}
	count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", count++, line);
		free(line);
	}
	close(fd);
}

void	test_invalid_fds(void)
{
	char	*line;

	printf("\n--- Test 5 - Testing FD Boundaries ---\n");
	line = get_next_line(-1);
	printf("fd -1: %s\n", line ? line : "NULL");
	if (line)
		free(line);
	line = get_next_line(FOPEN_MAX);
	printf("fd FOPEN_MAX (%d): %s\n", FOPEN_MAX, line ? line : "NULL");
	if (line)
		free(line);
}
void	test_multiple_fds(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	printf("\n--- Test 6 - Multiple FDs Simultaneously ---\n");
	fd1 = open("test1_bonus.txt", O_RDONLY);
	fd2 = open("test2_bonus.txt", O_RDONLY);
	fd3 = open("test3_bonus.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Error opening files\n");
		return ;
	}
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd1);
		printf("fd1 (%d) -> %s", fd1, line);
		free(line);
		line = get_next_line(fd2);
		printf("fd2 (%d) -> %s", fd2, line);
		free(line);
		line = get_next_line(fd3);
		printf("fd3 (%d) -> %s", fd3, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}

void	test_stdin(void)
{
	char	*line;
	int		count;

	printf("\n--- Test 7 - Standard input (type some lines, Ctrl+D to end) ---\n");
	count = 1;
	while ((line = get_next_line(0)) != NULL)
	{
		printf("Line %d: %s", count++, line);
		free(line);
	}
}

int	main(void)
{
	printf("\nTesting with BUFFER_SIZE = %d\n", BUFFER_SIZE);

	// Test 1: Normal file
	test_single_fd(open("test_normal_bonus.txt", O_RDONLY), "--- Test 1 - Normal file ---");

	// Test 2: Empty file
	test_single_fd(open("test_empty_bonus.txt", O_RDONLY), "--- Test 2 - Empty file ---");

	// Test 3: Single long line
	test_single_fd(open("test_long_bonus.txt", O_RDONLY), "--- Test 3 - Long line ---");

	// Test 4: Only newlines
	test_single_fd(open("test_newlines_bonus.txt", O_RDONLY), "\n--- Test 4 - Only newlines ---");

	// Test 5: Invalid FDs
	test_invalid_fds();
	
	// Test 6: Multiple FDs
	test_multiple_fds();

	// Test 7: Standard input (interactive)
	test_stdin();

	return (0);
}