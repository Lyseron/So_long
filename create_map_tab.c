/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:34:55 by lyaberge          #+#    #+#             */
/*   Updated: 2026/01/19 14:34:55 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// modified to remove the newline in each line 
// to get a **map with juste the component
static char	*ft_strdup_modified(const char *s)
{
	char	*tab;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

// create the **tab
static char	**ft_create_map_tab(char *av, int *fd)
{
	int		nb_of_line;
	char	**map;
	int		i;
	char	*line;

	i = 0;
	nb_of_line = ft_count_line(av);
	map = malloc(sizeof(char *) * (nb_of_line + 1));
	if (!map)
		return (NULL);
	line = get_next_line(*fd);
	while (line)
	{
		map[i] = ft_strdup_modified(line);
		if (!map[i])
			return (free_bail(map, i), free(map), NULL);
		free(line);
		line = get_next_line(*fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

// open the map.ber file and create the **map
int	ft_open_and_create_map_tab(t_game *g, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	g->map = ft_create_map_tab(argv[1], &fd);
	if (!g->map)
		return (-1);
	return (fd);
}
