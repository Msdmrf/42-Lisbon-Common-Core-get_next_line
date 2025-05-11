/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:46:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 14:00:06 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd >= 1024|| BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	line = NULL;
	if (buffer[fd][0])
		line = handle_buffer(&buffer[fd], &line);
	while (!ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes < 0 && line)
				free(line);
			if (bytes < 0)
				return (NULL);
			return (line);
		}
		buffer[fd][bytes] = '\0';
		line = handle_buffer(&buffer[fd], &line);
	}
	return (line);
}
