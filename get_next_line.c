/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:40:32 by migusant          #+#    #+#             */
/*   Updated: 2025/05/12 12:07:28 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0])
	{
		temp = ft_buffer_extract(buffer);
		if (!temp)
			return (NULL);
		line = ft_strjoin(line, temp);
		free(temp);
		ft_buffer_clean(buffer);
	}
	while (!ft_strlenchr(line, '\n', NULL))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes < 0 || !line || !*line)
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		buffer[bytes] = '\0';
		temp = ft_buffer_extract(buffer);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, temp);
		free(temp);
		ft_buffer_clean(buffer);
	}
	return (line);
}
