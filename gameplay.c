/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaberge <lyaberge@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-16 16:50:24 by lyaberge          #+#    #+#             */
/*   Updated: 2026-01-16 16:50:24 by lyaberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// player_row_x/y = position of the player
// possible_x/y = case to check if valid for the player to go
// up: dx = 0, dy = -1; down: dx = 0, dy = +1;
// left: dx = -1, dy = 0; right: dx = +1, dy = 0;
// next_player_pos_x/y = next sure position of the player 
int	ft_possible_move(t_game *g, int possible_x, int possible_y)
{
	char	current_tile;
	t_npp	n;

	n.next_player_pos_x = g->player_x + possible_x;
	n.next_player_pos_y = g->player_y + possible_y;
	if (n.next_player_pos_x < 0 || n.next_player_pos_y < 0)
		return (1);
	if (n.next_player_pos_y >= g->height || n.next_player_pos_x >= g->width)
		return (1);
	current_tile = g->map[n.next_player_pos_y][n.next_player_pos_x];
	if (current_tile == '1')
		return (1);
	if (current_tile == 'C')
	{
		g->collectible_collected++;
		g->map[n.next_player_pos_y][n.next_player_pos_x] = '0';
	}
	if (current_tile == 'E')
	{
		if (g->collectible_collected == g->collectible_total)
			return (write(1, "WIN\n", 4), 2);
	}
	g->player_y = n.next_player_pos_y;
	g->player_x = n.next_player_pos_x;
	g->moves++;
	return (0);
}
