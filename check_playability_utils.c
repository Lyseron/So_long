/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-16 15:30:44 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-16 15:30:44 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// to cpy the map to be able to write 'V' into the copy
// and check if the map is playable
char	**ft_copy_map(char **map)
{
	char	**copy;
	int		i;

	if (!map)
		return (NULL);
	copy = malloc(sizeof(char *) * (ft_count_str_in_dtab(map) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// to get the player first position on the **map
int	ft_found_player_pos(char **map, int	*x, int	*y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return (map[*y][*x] = '0', 1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}
