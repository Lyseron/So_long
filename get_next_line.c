/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 09:45:35 by lyaberge          #+#    #+#             */
/*   Updated: 2025-11-20 09:45:35 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*line_with_n_or_all_line(char *s)
{
	char	*tab;
	int		index_n;

	if (!s || s[0] == '\0')
		return (NULL);
	tab = NULL;
	index_n = ft_index_of_n(s);
	if (index_n == -1)
	{
		tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, s, (ft_strlen(s) + 1));
	}
	else if (index_n >= 0)
	{
		tab = malloc(sizeof(char) * (index_n + 2));
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, s, index_n + 2);
	}
	return (tab);
}

static char	*rest_after_newline(char *s, int index_newline)
{
	char	*tab;
	int		index_after_n;
	int		size;
	int		i;

	if (!s || s[0] == '\0')
		return (NULL);
	size = ft_strlen(s) - (index_newline + 1);
	if (size <= 0)
		return (NULL);
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	index_after_n = index_newline + 1;
	i = 0;
	while (s[index_after_n])
	{
		tab[i] = s[index_after_n];
		i++;
		index_after_n++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*assembly_and_free(char *pstash[])
{
	char	*line;
	char	*old_stash;
	int		index_n;

	if (!pstash || !pstash[0] || pstash[0][0] == '\0')
		return (NULL);
	line = line_with_n_or_all_line(pstash[0]);
	if (!line)
		return (free(pstash[0]), pstash[0] = NULL, NULL);
	index_n = ft_index_of_n(pstash[0]);
	if (index_n == -1)
		return (free(pstash[0]), pstash[0] = NULL, line);
	else
	{
		old_stash = pstash[0];
		pstash[0] = rest_after_newline(old_stash, index_n);
		free(old_stash);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	int			bytes_read;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_index_of_n(stash) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		stash = ft_strjoin_and_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	if (bytes_read < 0)
		return (free(stash), stash = NULL, NULL);
	return (assembly_and_free(&stash));
}
