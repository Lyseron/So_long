/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-13 10:20:32 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-13 10:20:32 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// free all the string in *tab and the tab
void	ft_free(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// to count the number of line in the map
// to know the size of *char to malloc to create the **map
int	ft_count_line(char *av)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

// count the number of line in the map
int	ft_count_str_in_dtab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
