/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-13 11:08:37 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-13 11:08:37 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// return and write in case of error 
static int	ft_error_component(int c, int p, int e)
{
	if (c < 1)
		return (1);
	if (p != 1)
		return (1);
	if (e != 1)
		return (1);
	return (0);
}

// init the struc component
static void	ft_init(t_comp *c)
{
	c->found_c = 0;
	c->found_e = 0;
	c->found_p = 0;
}

// to check if the map have all the necessary component
// to be a valid map 
// -> at least 1 collectible
// -> only 1 exit
// -> only 1 player
int	ft_check_map_component(char **map)
{
	t_comp	c;
	int		i;
	int		j;

	i = 0;
	ft_init(&c);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				c.found_e++;
			else if (map[i][j] == 'P')
				c.found_p++;
			else if (map[i][j] == 'C')
				c.found_c++;
			j++;
		}
		i++;
	}
	if (ft_error_component(c.found_c, c.found_p, c.found_e) == 1)
		return (1);
	return (0);
}
