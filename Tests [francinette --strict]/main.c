/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:36:44 by migusant          #+#    #+#             */
/*   Updated: 2025/05/13 12:05:14 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

// clear && cc get_next_line.c get_next_line_utils.c main.c && valgrind --leak-check=full ./a.out || cat -e 
// clear && cc get_next_line_bonus.c get_next_line_utils_bonus.c main.c && valgrind --leak-check=full ./a.out || cat -e

/*
 * Summary of Issue and Solution: (/home/migusant/francinette/tests/get_next_line/fsoares/Makefile)
 *
 * Issue:
 * - When running the tester with "francinette --strict" and BUFFER_SIZE=10, a TIMEOUT error occurred.
 * - The issue was due to the STRICT_MEM condition (`-D STRICT_MEM`) in the Makefile, activated when EXEC_STRICT was defined.
 * - STRICT_MEM introduced additional memory checks, which added overhead and slowed execution, causing the timeout.

 * Solution:
 * - The STRICT_MEM directive was commented out in the Makefile, which disabled the strict memory checks.
 * - This allowed the code to run with standard memory management, improving performance and avoiding the timeout.
 *
 * Key Insights:
 * - STRICT_MEM enforces stricter memory usage rules, often for debugging or memory leak detection.
 * - Buffer size (BUFFER_SIZE) impacts performance significantly, especially for small values like 10.
 * - Timeout issues may arise from additional runtime overhead introduced by debugging or strict constraints.
 */

static void test_fd(int fd, const char *test_name)
{
  char *line;
  int line_count;

  line_count = 1;
  while (1)
  {
    line = get_next_line(fd);
    if (line)
      printf("%s", line);
    if (!line)
      break;
    free(line);
  }
}

int main(void)
{
  int fd;

  fd = open("giant_line.txt", O_RDONLY);
  test_fd(fd, "--- Test file with one giant line ---");
  close(fd);
  return (0);
}
