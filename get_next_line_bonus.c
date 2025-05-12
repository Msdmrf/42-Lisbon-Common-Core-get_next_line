/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:46:30 by migusant          #+#    #+#             */
/*   Updated: 2025/05/12 16:03:51 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	if (buffer[fd][0])
	{
		temp = ft_buffer_extract(buffer[fd]);
		if (!temp)
			return (NULL);
		line = ft_strjoin(line, temp);
		free(temp);
		ft_buffer_clean(buffer[fd]);
	}
	while (!ft_strlenchr(line, '\n', NULL))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes < 0 || !line || !*line)
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		buffer[fd][bytes] = '\0';
		temp = ft_buffer_extract(buffer[fd]);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, temp);
		free(temp);
		ft_buffer_clean(buffer[fd]);
	}
	return (line);
}
