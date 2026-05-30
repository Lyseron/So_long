/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-12 12:42:50 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-12 12:42:50 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// to check if there is a wall of 1
static int	ft_check_wall_x(char *s)
{
	size_t	i;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

// check that all the exter wall are 1
// -> so the first and last line
//-> the bigining and end of every line from the second to the
// before last one 
int	ft_check_wall_extern(char **map)
{
	int	i;
	int	len;

	if (ft_check_wall_x(map[0]) == 1)
		return (1);
	if (ft_check_wall_x(map[ft_count_str_in_dtab(map) - 1]) == 1)
		return (1);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			len--;
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

// check if the map is a rectangle
// so all the line have the same number of char
int	ft_check_is_rectangle(char **map)
{
	int		i;
	size_t	len_line;
	int		nb_of_line;

	i = 0;
	len_line = ft_strlen(map[0]);
	nb_of_line = ft_count_str_in_dtab(map);
	while (i < nb_of_line)
	{
		if (len_line != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}
