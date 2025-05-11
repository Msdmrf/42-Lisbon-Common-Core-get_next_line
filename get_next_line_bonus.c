/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:46:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 20:21:05 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0])
		line = ft_bufexclean(buffer[fd], &line);
	while (!ft_strlenchr(line, '\n', NULL))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			if (line)
				free(line);
			buffer[fd][0] = '\0';
			return (NULL);
		}
		if (bytes == 0)
		{
			buffer[fd][0] = '\0';
			return (line);
		}
		buffer[fd][bytes] = '\0';
		line = ft_bufexclean(buffer[fd], &line);
	}
	return (line);
}
