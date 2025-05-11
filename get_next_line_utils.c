/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:00 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 17:57:46 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strutil(const char *s, int c, size_t *len)
{
	size_t	i;
	char	*found;

	i = 0;
	found = NULL;
	if (!s)
	{
		if (len)
			*len = 0;
		return (NULL);
	}
	while (s[i])
	{
		if (!found && s[i] == (char)c)
			found = (char *)&s[i];
		i++;
	}
	if (!found && s[i] == (char)c)
		found = (char *)&s[i];
	if (len)
		*len = i;
	return (found);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	lens[2];
	size_t	idx[2];

	if (!s2)
		return (NULL);
	ft_strutil(s1, 0, &lens[0]);
	ft_strutil(s2, 0, &lens[1]);
	str = malloc(lens[0] + lens[1] + 1);
	if (!str)
		return (NULL);
	idx[0] = 0;
	idx[1] = 0;
	if (s1)
	{
		while (s1[idx[0]])
			str[idx[1]++] = s1[idx[0]++];
		free(s1);
	}
	idx[0] = 0;
	while (s2[idx[0]])
		str[idx[1]++] = s2[idx[0]++];
	str[idx[1]] = '\0';
	return (str);
}

void	*handle_buffer(char *buffer, char **line)
{
	char	*temp;
	size_t	len;
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = i;
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	*line = ft_strjoin(*line, temp);
	free(temp);
	clean_buffer(buffer);
	return (*line);
}

void	clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
