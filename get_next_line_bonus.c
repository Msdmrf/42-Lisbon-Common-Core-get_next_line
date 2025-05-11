/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:46:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 19:30:37 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
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
		line = ft_bufexclean(&buffer[fd], &line);
	while (!ft_strlenchr(line, '\n', NULL))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (NULL);
		}
		if (bytes == 0)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (line);
		}
		buffer[fd][bytes] = '\0';
		line = ft_bufexclean(&buffer[fd], &line);
	}
	return (line);
}
