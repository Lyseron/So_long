/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 09:45:21 by lyaberge          #+#    #+#             */
/*   Updated: 2025-11-20 09:45:21 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_and_free(char *stash, char *buf)
{
	char	*tab;
	int		i;
	int		j;
	int		size;

	if (!stash)
		return (ft_strdup(buf));
	size = ft_strlen(stash) + ft_strlen(buf);
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (free(stash), NULL);
	i = 0;
	while (stash[i])
	{
		tab[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
		tab[i++] = buf[j++];
	tab[i] = '\0';
	free(stash);
	return (tab);
}

int	ft_index_of_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
