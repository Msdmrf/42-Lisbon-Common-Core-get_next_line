/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:17 by migusant          #+#    #+#             */
/*   Updated: 2025/05/11 18:32:04 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_bufexclean(char **buffer, char **line)
{
	char	*temp;
	size_t	idx[2];
	size_t	len;

	idx[0] = 0;
	while ((*buffer)[idx[0]] && (*buffer)[idx[0]] != '\n')
		idx[0]++;
	if ((*buffer)[idx[0]] == '\n')
		idx[0]++;
	len = idx[0];
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	idx[0] = -1;
	while (++idx[0] < len)
		temp[idx[0]] = (*buffer)[idx[0]];
	temp[len] = '\0';
	*line = ft_strjoin(*line, temp);
	free(temp);
	idx[1] = 0;
	while ((*buffer)[idx[0]])
		(*buffer)[idx[1]++] = (*buffer)[idx[0]++];
	(*buffer)[idx[1]] = '\0';
	return (*line);
}
