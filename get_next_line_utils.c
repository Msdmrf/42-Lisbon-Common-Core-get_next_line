/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:00 by migusant          #+#    #+#             */
/*   Updated: 2025/05/12 12:07:03 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlenchr(const char *s, int c, size_t *len)
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
	ft_strlenchr(s1, 0, &lens[0]);
	ft_strlenchr(s2, 0, &lens[1]);
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

char	*ft_buffer_extract(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	len;

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
	temp[len] = '\0';
	return (temp);
}

void	ft_buffer_clean(char *buffer)
{
	size_t	i;
	size_t	j;

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
