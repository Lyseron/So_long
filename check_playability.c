/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-16 13:28:15 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-16 13:28:15 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_final_check(char **map)
{
	if (ft_check_is_rectangle(map) == 1)
		return (1);
	if (ft_check_wall_extern(map) == 1)
		return (1);
	if (ft_check_map_component(map) == 1)
		return (1);
	if (ft_check_playable(map) == 1)
		return (1);
	return (0);
}

// to check if the map is playable
// check all the path that are not 1 and not already seen = 'V'
static void	ft_flood_fill(char **cpy, int x, int y, t_found *f)
{
	int	height;
	int	width;

	height = ft_count_str_in_dtab(cpy);
	width = ft_strlen(cpy[0]);
	if (x < 0 || y < 0 || y >= height || x >= width)
		return ;
	if (cpy[y][x] == 'X' || cpy[y][x] == '1')
		return ;
	if (cpy[y][x] == 'E')
		f->exit = 1;
	if (cpy[y][x] == 'C')
		f->collectible++;
	cpy[y][x] = 'X';
	ft_flood_fill(cpy, x - 1, y, f);
	ft_flood_fill(cpy, x + 1, y, f);
	ft_flood_fill(cpy, x, y - 1, f);
	ft_flood_fill(cpy, x, y + 1, f);
}

// create a cpy of the map then check if it's playable
// by putting 'V' into the path that is not 1
// and see if we can access all collectible and the exit
// from the player position
int	ft_check_playable(char **map)
{
	char	**cpy;
	int		x;
	int		y;
	t_found	f;
	int		total_collectible;

	x = 0;
	y = 0;
	total_collectible = ft_count_collectible(map);
	cpy = ft_copy_map(map);
	if (!cpy)
		return (1);
	ft_found_player_pos(cpy, &x, &y);
	f.collectible = 0;
	f.exit = 0;
	ft_flood_fill(cpy, x, y, &f);
	if (f.collectible != total_collectible || f.exit != 1)
		return (ft_free(cpy), 1);
	ft_free(cpy);
	return (0);
}
